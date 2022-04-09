// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful, but
// WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
// General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program. If not, see <https://www.gnu.org/licenses/>.
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
