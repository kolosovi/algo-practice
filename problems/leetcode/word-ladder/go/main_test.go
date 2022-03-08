package word_ladder

import (
	"testing"

	"github.com/stretchr/testify/require"
)

func Test_ladderLength(t *testing.T) {
	cases := []struct {
		name      string
		beginWord string
		endWord   string
		wordList  []string
		expected  int
	}{
		{
			name:      "example 1",
			beginWord: "hit",
			endWord:   "cog",
			wordList:  []string{"hot", "dot", "dog", "lot", "log", "cog"},
			expected:  5,
		},
		{
			name:      "example 2",
			beginWord: "hit",
			endWord:   "cog",
			wordList:  []string{"hot", "dot", "dog", "lot", "log"},
			expected:  0,
		},
		{
			name:      "large",
			beginWord: "qa",
			endWord:   "sq",
			wordList: []string{
				"si",
				"go",
				"se",
				"cm",
				"so",
				"ph",
				"mt",
				"db",
				"mb",
				"sb",
				"kr",
				"ln",
				"tm",
				"le",
				"av",
				"sm",
				"ar",
				"ci",
				"ca",
				"br",
				"ti",
				"ba",
				"to",
				"ra",
				"fa",
				"yo",
				"ow",
				"sn",
				"ya",
				"cr",
				"po",
				"fe",
				"ho",
				"ma",
				"re",
				"or",
				"rn",
				"au",
				"ur",
				"rh",
				"sr",
				"tc",
				"lt",
				"lo",
				"as",
				"fr",
				"nb",
				"yb",
				"if",
				"pb",
				"ge",
				"th",
				"pm",
				"rb",
				"sh",
				"co",
				"ga",
				"li",
				"ha",
				"hz",
				"no",
				"bi",
				"di",
				"hi",
				"qa",
				"pi",
				"os",
				"uh",
				"wm",
				"an",
				"me",
				"mo",
				"na",
				"la",
				"st",
				"er",
				"sc",
				"ne",
				"mn",
				"mi",
				"am",
				"ex",
				"pt",
				"io",
				"be",
				"fm",
				"ta",
				"tb",
				"ni",
				"mr",
				"pa",
				"he",
				"lr",
				"sq",
				"ye",
			},
			expected: 5,
		},
	}
	for _, tc := range cases {
		t.Run(tc.name, func(t *testing.T) {
			actual := ladderLength(tc.beginWord, tc.endWord, tc.wordList)
			require.Equal(t, tc.expected, actual)
		})
	}
}
