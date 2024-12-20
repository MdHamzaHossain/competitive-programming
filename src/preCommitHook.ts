import { join } from "path";
import { updateCodeforcesMd } from "./codeforces/codeforcesUpdateMD.js";
import { updateTophMd } from "./toph/tophUpdateMD.js";
import * as fsp from "fs/promises";
import { markdownTable } from "markdown-table";

async function main() {
    const langChart: string[][] = [["Language", "Solves"]];
    const platforms = ["codeforces", "toph"];
    const platformData = [await updateCodeforcesMd(), await updateTophMd()];

    const platformChart: string[][] = [["Platform", "Total Submissions", "Total Unique Solved"]];

    platformData.forEach((a, i) => {
        a.shift();
        platformChart.push([platforms[i], a.at(-2)?.[1] || "0", a.at(-1)?.[1] || "0"]);
    });
    platformData[0].forEach(([k], i) => {
        const totalAmount = platformData.reduce((a, b) => a + +b[i][1], 0);
        langChart[i + 1] = [k, "" + totalAmount];
    });
    const oldReadMe = await fsp.readFile(join(process.cwd(), "README.md"), { encoding: "utf-8" });
    const oldReadMeData = oldReadMe.split("## Stats")[0] || "";
    const completeString =
        "### Per Platform\n\n" +
        markdownTable(platformChart, { align: "c".repeat(platformChart[0].length) }) +
        "\n\n" +
        "### Per Language\n\n" +
        markdownTable(langChart, { align: "c".repeat(langChart[0].length) }) +
        "\n";
    await fsp.writeFile(join(process.cwd(), "README.md"), oldReadMeData + "## Stats\n\n" + completeString);
}
main();
