import * as fsp from "fs/promises";
import { join } from "path";
import { markdownTable } from "markdown-table";
import FastGlob from "fast-glob";
import { supportedLanguages } from "../config.js";

main();
async function main() {
    const pathToToph = join(process.cwd(), "solves", "toph");
    // The list of languages I use
    const listOfExt = supportedLanguages;
    const titleAndIndexMatcherRegex = /(?<Index>\d+)\. (?<Title>.+)/;

    const fileObj: { [index: string]: number } = {};
    listOfExt.forEach((a) => (fileObj[a] = 0));

    const mainFolders = await FastGlob("solves/toph/**/**");
    const fileMapper = new Map<string, string[]>();

    const problemTrackerArray: string[][] = [["Problem name", ...listOfExt]];

    for (const folder of mainFolders) {
        const file = folder.split("/").at(-2) || "";
        const matchedDir = file.match(titleAndIndexMatcherRegex);
        const { Index, Title } = matchedDir?.groups || {};
        if (!Index || !Title) continue;

        const fileExtension = folder.split(".").pop() || "";
        const extensionIndex = listOfExt.indexOf(fileExtension);
        if (extensionIndex < 0) continue;
        const url = formattedTitleToURL(Title);
        const hyperLinked = `[${file}](${url})`;
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
    }
    for (const [name, ind] of fileMapper.entries()) {
        const resultArray: string[] = [name, ...ind.map((a) => a || "❎")];
        problemTrackerArray.push(resultArray);
    }

    const counterArray: string[][] = [["Language", "Solves"]];
    let totalCounter = 0;
    listOfExt.forEach((a) => {
        counterArray.push([a, "" + fileObj[a]]);
        totalCounter += fileObj[a];
    });
    counterArray.push(["Total", "" + totalCounter]);

    const completeString =
        "### Amount of solves" +
        "\n\n" +
        markdownTable(counterArray) +
        "\n\n" +
        "### Problems" +
        "\n\n" +
        markdownTable(
            problemTrackerArray.sort((a, b) => {
                return parseInt(a[0].substring(1, 5)) - parseInt(b[0].substring(1, 5));
            }),
        ) +
        "\n";

    const oldReadMe = await fsp.readFile(join(pathToToph, "README.md"), { encoding: "utf-8" });
    const oldReadMeData = oldReadMe.split("## Stats")[0] || "";
    await fsp.writeFile(join(pathToToph, "README.md"), oldReadMeData + "## Stats\n\n" + completeString);
}
function formattedTitleToURL(s: string): string {
    return "https://toph.co/p/" + s.toLowerCase().replace(/ /gim, "-");
}
