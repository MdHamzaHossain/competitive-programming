import { join } from "path";
import { supportedLanguages } from "../config.js";
import * as fsp from "fs/promises";
import readline from "node:readline/promises";
import { gql, request } from "graphql-request";

export interface LeetcodeQuestion {
    difficulty: string;
    frontendQuestionId: string;
    title: string;
    titleSlug: string;
    topicTags: TopicTag[];
}
interface TopicTag {
    name: string;
    slug: string;
}
export interface CodeforcesProblemInterface {
    contestId: number;
    index: string;
    name: string;
    type: string;
    rating: number;
    tags: string[];
}
let problemsCache: LeetcodeQuestion[] | undefined = undefined;
export async function fetchLeetcodeData(): Promise<LeetcodeQuestion[] | undefined> {
    if (problemsCache) {
        return problemsCache;
    }
    const problems: LeetcodeQuestion[] = await request(
        "https://leetcode.com/graphql",
        gql`
            query problemsetQuestionList(
                $categorySlug: String
                $limit: Int
                $skip: Int
                $filters: QuestionListFilterInput
            ) {
                problemsetQuestionList: questionList(
                    categorySlug: $categorySlug
                    limit: $limit
                    skip: $skip
                    filters: $filters
                ) {
                    total: totalNum
                    questions: data {
                        difficulty
                        frontendQuestionId: questionFrontendId
                        title
                        titleSlug
                        topicTags {
                            name
                            slug
                        }
                    }
                }
            }
        `,
        { categorySlug: "", skip: 0, limit: 5000, filters: {} },
    )
        // eslint-disable-next-line @typescript-eslint/ban-ts-comment
        // @ts-ignore
        .then((a) => a?.["problemsetQuestionList"]?.questions)
        .catch(() => undefined);
    if (problems) problemsCache = problems;
    return problems;
}

export async function handleLeetcode(url: string, r1: readline.Interface) {
    let listOfExt = supportedLanguages;
    const pathToLeetcode = join(process.cwd(), "solves", "leetcode");
    const { problemSlug } = url.match(/(?:problems\/(?<problemSlug>[^/]+))/)?.groups || {};

    const problems = await fetchLeetcodeData().catch(() => undefined);
    if (!problems) throw new Error("Problem fetching codeforces data");

    const foundProblem = problems.find((a) => problemSlug === a.titleSlug);
    console.log(foundProblem);
    if (!foundProblem) throw new Error("This problem has no entry");

    const formattedTitle = `${foundProblem.frontendQuestionId}_${foundProblem.titleSlug}`;

    const readDir = await fsp.readdir(pathToLeetcode);
    const foundDir = readDir.includes(formattedTitle);

    if (foundDir) {
        console.log("You already have an entry with the same title. The missing language variants will be added");
        const pathToQuestion = join(pathToLeetcode, formattedTitle);

        const files = await fsp.readdir(pathToQuestion);
        const existingExtensions = files.map((a) => a.split(".").pop());
        listOfExt = listOfExt.filter((a) => !existingExtensions.includes(a)).sort();
    }

    const pathToQuestion = join(pathToLeetcode, formattedTitle);

    await fsp.mkdir(`${pathToQuestion}`, { recursive: true });
    const comments = await r1.question("Add any additional comments: \n");
    const templateMD = await fsp.readFile(join(process.cwd(), "templates", "leetcodeNotes.md"), {
        encoding: "utf-8",
    });
    const existingComments = (
        await fsp.readFile(join(pathToQuestion, "README.md"), { encoding: "utf-8" }).catch(() => "")
    )?.trim();
    const content =
        existingComments ||
        templateMD
            .replaceAll(/({{%formattedTitle}})/g, formattedTitle)
            .replaceAll(/({{%comments}})/g, comments)
            .replaceAll(/({{%difficulty}})/g, "" + foundProblem.difficulty)
            .replaceAll(/({{%tags}})/g, foundProblem.topicTags.map((a) => `- ${a.name}`).join("\n"))
            .replaceAll(/{{%url}}/g, url);

    await fsp.writeFile(join(pathToQuestion, "README.md"), content);

    const fileExtensions = (
        await r1.question(
            "In which language(s) did you solve this question?\n" +
                listOfExt.sort().join(", ") +
                "\nEnter a list of extensions separated by commas:\n",
        )
    )
        .split(",")
        .map((a) => a.trim().toLowerCase());
    await Promise.all(
        listOfExt.map((ext) => {
            if (fileExtensions.includes(ext)) {
                return fsp.writeFile(
                    join(pathToQuestion, `${ext.toUpperCase()} ${formattedTitle}.${ext.replace("golfjs", "js")}`),
                    "",
                );
            }
        }),
    );
    console.log("\n\n\n");
}
