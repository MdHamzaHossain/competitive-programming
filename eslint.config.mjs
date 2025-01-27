import typescriptEslint from "@typescript-eslint/eslint-plugin";
import prettier from "eslint-plugin-prettier";
import globals from "globals";
import tsParser from "@typescript-eslint/parser";
import path from "node:path";
import { fileURLToPath } from "node:url";
import js from "@eslint/js";
import { FlatCompat } from "@eslint/eslintrc";

const __filename = fileURLToPath(import.meta.url);
const __dirname = path.dirname(__filename);
const compat = new FlatCompat({
    baseDirectory: __dirname,
    recommendedConfig: js.configs.recommended,
    allConfig: js.configs.all,
});

export default [
    {
        ignores: ["**/dist", "**/node_modules"],
    },
    ...compat.extends("eslint:recommended", "plugin:@typescript-eslint/recommended", "plugin:prettier/recommended"),
    {
        plugins: {
            "@typescript-eslint": typescriptEslint,
            prettier,
        },

        languageOptions: {
            globals: {
                ...globals.node,
            },

            parser: tsParser,
            ecmaVersion: "latest",
            sourceType: "module",
        },

        rules: {
            "prettier/prettier": [
                "error",
                {},
                {
                    usePrettierrc: true,
                },
            ],

            indent: "off",
            //            "linebreak-style": ["error", "unix"],
            quotes: ["error", "double"],
            semi: ["error", "always"],
            "no-var": "error",
            "prefer-const": "error",
            "@typescript-eslint/no-non-null-assertion": "off",
        },
    },
];
