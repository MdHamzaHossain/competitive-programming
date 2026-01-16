import { gql } from "graphql-request";

export const leetCodeSelectProblemGraphQl = gql`
    query selectProblem($titleSlug: String!) {
        question(titleSlug: $titleSlug) {
            questionId
            questionFrontendId
            title
            titleSlug
            content
            difficulty
            topicTags {
                name
                slug
            }
        }
    }
`;
