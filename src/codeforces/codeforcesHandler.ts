import { join } from "path";
import { supportedLanguages } from "../config.js";
import * as fsp from "fs/promises";
import readline from "node:readline/promises";

export interface CodeforcesProblemInterface {
    contestId: number;
    index: string;
    name: string;
    type: string;
    rating: number;
    tags: string[];
}
export async function fetchCodeforcesData(): Promise<CodeforcesProblemInterface[] | undefined> {
    const jsonReq = await (
        await fetch("https://codeforces.com/api/problemset.problems", { method: "GET" }).catch(() => undefined)
    )
        ?.json()
        .catch(() => undefined);
    const problems: CodeforcesProblemInterface[] = jsonReq?.result?.problems;
    return problems;
}

export async function handleCodeforces(url: string, r1: readline.Interface) {
    let listOfExt = supportedLanguages;
    const pathToCodeforces = join(process.cwd(), "solves", "codeforces");
    const { contestId1, contestIndex1, contestId2, contestIndex2 } =
        url.match(
            /(?:problem\/(?<contestId1>[^/]+)(?:\/(?<contestIndex1>.+))?)|(?:contest\/(?<contestId2>.+)\/problem\/(?<contestIndex2>.+))/,
        )?.groups || {};
    const contestId = contestId1 ?? contestId2,
        contestIndex = contestIndex1 ?? contestIndex2;

    const problems = await fetchCodeforcesData().catch(() => undefined);
    if (!problems) throw new Error("Problem fetching codeforces data");

    const foundProblem = problems.find((a) => contestId == "" + a.contestId && a.index && a.index == contestIndex);

    if (!foundProblem) throw new Error("This problem has no entry");

    // const titleAndIndexMatcherRegex = /(?<Index>\d+)\. (?<Title>.+)/;
    // const title = url.split("/")?.pop() || "";
    // if (!title) process.exit();
    const formattedTitle = `${foundProblem.contestId}${foundProblem.index && `-${foundProblem.index}`}${foundProblem.name && `-${foundProblem.name}`}`;

    const readDir = await fsp.readdir(pathToCodeforces);
    // // Take out the readme
    // readDir.pop();
    const foundDir = readDir.includes(formattedTitle);
    // .find((a) => {
    //     return formattedTitle === a;
    // })
    // ?.trim();

    if (foundDir) {
        console.log("You already have an entry with the same title. The missing language variants will be added");
        const pathToQuestion = join(pathToCodeforces, formattedTitle);

        const files = await fsp.readdir(pathToQuestion);
        const existingExtensions = files.map((a) => a.split(".").pop());
        listOfExt = listOfExt.filter((a) => !existingExtensions.includes(a)).sort();
    }
    // const matchedDir = (foundDir || readDir.at(-1))?.match(titleAndIndexMatcherRegex);
    // const { Index } = matchedDir?.groups || {};
    // const indexNum = +Index || 0;
    // //const indexNum = a.at(-1)?.match(/(?<Index>\d+)\. (<Title>?.+)/)?.[0] || 0;
    const pathToQuestion = join(
        pathToCodeforces,
        formattedTitle,
        //     `${+indexNum + (foundDir ? 0 : 1)}`.padStart(4, "0") + ". " + formattedTitle,
    );

    await fsp.mkdir(`${pathToQuestion}`, { recursive: true });
    const comments = await r1.question("Add any additional comments: \n");
    const templateMD = await fsp.readFile(join(process.cwd(), "templates", "codeforcesNotes.md"), {
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
            .replaceAll(/({{%rating}})/g, "" + foundProblem.rating)
            .replaceAll(/({{%tags}})/g, foundProblem.tags.map((a) => `- ${a}`).join("\n"))
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
// function formatTitleString(str: string): string {
//     return str[0].toUpperCase() + str.slice(1).replace(/-(?<T>.)/g, (v: string) => v.replace("-", " ").toUpperCase());
// }
// function codeforcesURLToTitle(url: string): string {
//     return `${url.split("/").at(-2) || ""}${url.split("/").at(-1) || ""}`;
// }
