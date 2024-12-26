import * as fsp from "fs/promises";
import { join } from "path";
import { markdownTable } from "markdown-table";
import FastGlob from "fast-glob";
import { supportedLanguages } from "../config.js";
import { fetchLeetcodeData, LeetcodeQuestion } from "./leetcodeHandler.js";

export async function updateLeetcodeMd() {
    const problems = await fetchLeetcodeData().catch(() => undefined);

    if (!problems) throw new Error("Problem fetching leetcode data");
    const pathToLeetcode = join(process.cwd(), "solves", "leetcode");
    // The list of languages I use
    const listOfExt = supportedLanguages;
    const titleAndIndexMatcherRegex = /(?<leetIndex>\d+)_(?:(?<leetProbSlug>.+))/;

    const fileObj: { [index: string]: number } = {};
    listOfExt.forEach((a) => (fileObj[a] = 0));

    const mainFolders = await FastGlob("solves/leetcode/**/**");
    const fileMapper = new Map<string, string[]>();
    const infoMapper = new Map<string, Pick<LeetcodeQuestion, "difficulty" | "topicTags">>();

    const problemTrackerArray: string[][] = [["Problem name", "Difficulty", "Tags", ...listOfExt]];
    let maxIndex = 0;
    for (const folder of mainFolders) {
        const file = folder.split("/").at(-2) || "";
        const matchedDir = file.match(titleAndIndexMatcherRegex);
        const { leetProbSlug } = matchedDir?.groups || {};
        if (!leetProbSlug) continue;
        maxIndex = Math.max(maxIndex, +0);
        const fileExtension = folder.split(".").pop() || "";
        const extensionIndex = listOfExt.indexOf(fileExtension);
        if (extensionIndex < 0) continue;
        const url = formattedTitleToURL(leetProbSlug);
        const hyperLinked = `[${file}](${url})`;

        const foundProblem = problems.find((a) => leetProbSlug == a.titleSlug);

        if (!foundProblem) throw new Error("This problem has no entry");

        const mapEntry =
            fileMapper.get(hyperLinked) ??
            fileMapper
                .set(
                    hyperLinked,
                    Array.from({ length: listOfExt.length }, () => ""),
                )
                .get(hyperLinked)!;

        mapEntry[extensionIndex] = `[${fileExtension}](<../../${folder}>)`;
        fileObj[fileExtension]++;
        if (!infoMapper.get(hyperLinked))
            infoMapper.set(hyperLinked, { difficulty: foundProblem.difficulty, topicTags: foundProblem.topicTags });
    }
    for (const [name, ind] of fileMapper.entries()) {
        const info = infoMapper.get(name);
        if (!info) throw new Error("Info not found");
        const resultArray: string[] = [
            name,
            info.difficulty,
            //info.tags.map((a) => `• ${a}`).join("<br>"),
            info.topicTags.map((a) => a.name).join(", "),
            ...ind.map((a) => a || "❎"),
        ];
        problemTrackerArray.push(resultArray);
    }

    const counterArray: string[][] = [["Language", "Solves"]];
    let totalCounter = 0;
    listOfExt.forEach((a) => {
        counterArray.push([a, "" + fileObj[a]]);
        totalCounter += fileObj[a];
    });
    counterArray.push(["Total submissions", "" + totalCounter]);
    counterArray.push(["Total unique solved", "" + fileMapper.size]);

    const completeString =
        "### Amount of successful solves" +
        "\n\n" +
        markdownTable(
            //TODO check if it has any lang constraints
            // counterArray.filter((a) => !["swift", "lua"].includes(a[0])),
            counterArray.filter((a) => a[1] != "0"),
            { align: "cc" },
        ) +
        "\n\n" +
        "### Problems" +
        "\n\n" +
        markdownTable(
            problemTrackerArray.sort((a, b) => {
                return parseInt(a[0].substring(1, 5)) - parseInt(b[0].substring(1, 5));
            }),
        ) +
        "\n";

    const oldReadMe = await fsp.readFile(join(pathToLeetcode, "README.md"), { encoding: "utf-8" });
    const oldReadMeData = oldReadMe.split("## Stats")[0] || "";
    await fsp.writeFile(join(pathToLeetcode, "README.md"), oldReadMeData + "## Stats\n\n" + completeString);
    return counterArray;
}

function formattedTitleToURL(titleSlug: string) {
    return "https://leetcode.com/problems/" + titleSlug;
}
