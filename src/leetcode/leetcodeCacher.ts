import request from "graphql-request";
import { leetcodeProblemSetQuestionListV2GraphQl } from "./leetcodeQueries/leetcodeProblemSetQuestionListV2.js";
import { setTimeout } from "node:timers/promises";
import { mkdir, readFile, writeFile } from "node:fs/promises";
import { join } from "node:path";

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
interface problemsetQuestionListV2 {
    questions: Array<{
        difficulty: string;
        questionFrontendId: string;
        title: string;
        id: number;
        titleSlug: string;
        topicTags: TopicTag[];
    }>;
    totalLength: number;
    finishedLength: number;
    hasMore: boolean;
}
let cache: LeetcodeQuestion[] = [];
async function fetchLeetcodeProblems(limit: number, skip: number): Promise<problemsetQuestionListV2 | undefined> {
    return (
        request("https://leetcode.com/graphql", leetcodeProblemSetQuestionListV2GraphQl, { skip, limit })
            // eslint-disable-next-line @typescript-eslint/ban-ts-comment
            // @ts-ignore
            .then((a) => a?.["problemsetQuestionListV2"])
            .catch(() => undefined) as Promise<problemsetQuestionListV2 | undefined>
    );
}

export async function leetcodeCacher(initial: number = 0) {
    const pathToCache = join(process.cwd(), "cache", "leetcode");
    await mkdir(pathToCache, { recursive: true }).catch(() => {
        throw new Error(`Failed to create: ${pathToCache}`);
    });
    const pathToCacheFile = join(pathToCache, "leetcodeCache.json");
    let skip = initial;
    if (skip == 0) {
        const preCache = await readFile(pathToCacheFile, { encoding: "utf8" }).catch(() => undefined);
        if (preCache) {
            const data: LeetcodeQuestion[] = JSON.parse(preCache);
            cache = data;
            skip = data.length;
        }
    }
    let total = -1;
    await fetchLeetcodeProblems(0, 0).then((a) => {
        total = a?.totalLength ?? -1;
    });
    if (total == -1) throw new Error("Failed To fetch initial leetcode data");
    let hasMore = true;
    while (hasMore) {
        await setTimeout(1000);
        const res = await fetchLeetcodeProblems(100, skip);
        if (!res) {
            //  console.debug(`Leetcode, this ends here ${skip}/${total}`);
            break;
        }
        res.questions.forEach(({ difficulty, questionFrontendId, title, topicTags, titleSlug }) => {
            const a: LeetcodeQuestion = {
                difficulty,
                frontendQuestionId: questionFrontendId,
                title,
                titleSlug,
                topicTags: topicTags.map(({ slug, name }) => ({ slug, name })),
            };
            cache.push(a);
        });
        skip += res.questions.length;
        // console.debug(`Saved ${skip}/${total}`);
        hasMore = res.hasMore;
    }

    await writeFile(pathToCacheFile, JSON.stringify(cache)).catch(() => {
        throw new Error(`Failed to create leetcode cache: ${pathToCacheFile}`);
    });
    return cache.length ? cache : undefined;
}
