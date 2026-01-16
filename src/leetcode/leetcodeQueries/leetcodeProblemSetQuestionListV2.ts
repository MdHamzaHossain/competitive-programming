import { gql } from "graphql-request";

export const leetcodeProblemSetQuestionListV2GraphQl = gql`
    query problemsetQuestionListV2($limit: Int, $skip: Int) {
        problemsetQuestionListV2(limit: $limit, skip: $skip) {
            questions {
                id
                titleSlug
                title
                translatedTitle
                questionFrontendId
                difficulty
                topicTags {
                    name
                    slug
                    nameTranslated
                }
            }
            totalLength
            finishedLength
            hasMore
        }
    }
`;
