import * as fsp from "fs/promises";
import { join } from "path";
import { markdownTable } from "markdown-table";
import FastGlob from "fast-glob";
import { supportedLanguages } from "../config.js";
import { CodeforcesProblemInterface, fetchCodeforcesData } from "./codeforcesHandler.js";

export async function updateCodeforcesMd() {
    const problems = await fetchCodeforcesData().catch(() => undefined);
    if (!problems) throw new Error("Problem fetching codeforces data");
    const pathToCodeforces = join(process.cwd(), "solves", "codeforces");
    // The list of languages I use
    const listOfExt = supportedLanguages;
    const titleAndIndexMatcherRegex = /(?<contestID>\d+)(?:-(?<contestIndex>[A-Za-z0-9]+))?-(?<ProbName>.+)/;

    const fileObj: { [index: string]: number } = {};
    listOfExt.forEach((a) => (fileObj[a] = 0));

    const mainFolders = await FastGlob("solves/codeforces/**/**");
    const fileMapper = new Map<string, string[]>();
    const infoMapper = new Map<string, Pick<CodeforcesProblemInterface, "rating" | "tags">>();

    const problemTrackerArray: string[][] = [["Problem name", "Rating", "Tags", ...listOfExt]];
    console.log(mainFolders);
    let maxIndex = 0;
    for (const folder of mainFolders) {
        const file = folder.split("/").at(-2) || "";
        const matchedDir = file.match(titleAndIndexMatcherRegex);
        const { contestID, contestIndex } = matchedDir?.groups || {};
        if (!contestID) continue;
        maxIndex = Math.max(maxIndex, +0);
        const fileExtension = folder.split(".").pop() || "";
        const extensionIndex = listOfExt.indexOf(fileExtension);
        if (extensionIndex < 0) continue;
        const url = formattedTitleToURL(contestID, contestIndex);
        const hyperLinked = `[${file}](${url})`;

        const foundProblem = problems.find((a) => contestID == "" + a.contestId && a.index && a.index == contestIndex);

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
            infoMapper.set(hyperLinked, { rating: foundProblem.rating, tags: foundProblem.tags });
    }
    for (const [name, ind] of fileMapper.entries()) {
        const info = infoMapper.get(name);
        if (!info) throw new Error("Info not found");
        const resultArray: string[] = [
            name,
            "" + info.rating,
            //info.tags.map((a) => `• ${a}`).join("<br>"),
            info.tags.join(", "),
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
            counterArray.filter((a) => !["swift", "lua"].includes(a[0])),
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

    const oldReadMe = await fsp.readFile(join(pathToCodeforces, "README.md"), { encoding: "utf-8" });
    const oldReadMeData = oldReadMe.split("## Stats")[0] || "";
    await fsp.writeFile(join(pathToCodeforces, "README.md"), oldReadMeData + "## Stats\n\n" + completeString);
    return counterArray;
    /*

    */
}
function formattedTitleToURL(contestId: string, contestIndex?: string) {
    return "https://codeforces.com/problemset/problem/" + contestId + (contestIndex && `/${contestIndex}`);
}
