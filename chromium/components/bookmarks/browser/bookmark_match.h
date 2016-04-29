// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef COMPONENTS_BOOKMARKS_BROWSER_BOOKMARK_TITLE_MATCH_H_
#define COMPONENTS_BOOKMARKS_BROWSER_BOOKMARK_TITLE_MATCH_H_

#include <stddef.h>

#include <cstddef>
#include <utility>
#include <vector>

namespace bookmarks {

class BookmarkNode;

struct BookmarkMatch {
  // Each MatchPosition is the [begin, end) positions of a match within a
  // string.
  typedef std::pair<size_t, size_t> MatchPosition;
  typedef std::vector<MatchPosition> MatchPositions;

  // Type of match: of title, or of nickname
  enum match_type {kTitle, kNick, kDescription};

  BookmarkMatch(match_type kind = kTitle);
  ~BookmarkMatch();

  // Extracts and returns the offsets from |match_positions|.
  static std::vector<size_t> OffsetsFromMatchPositions(
      const MatchPositions& match_positions);

  // Replaces the offsets in |match_positions| with those given in |offsets|,
  // deleting any which are npos, and returns the updated list of match
  // positions.
  static MatchPositions ReplaceOffsetsInMatchPositions(
      const MatchPositions& match_positions,
      const std::vector<size_t>& offsets);

  // Type of match
  match_type match_kind;

  // The matching node of a query.
  const BookmarkNode* node;

  // Location of the matching words in the title of the node.
  MatchPositions title_match_positions;

  // Location of the matching words in the URL of the node.
  MatchPositions url_match_positions;
};

}  // namespace bookmarks

#endif  // COMPONENTS_BOOKMARKS_BROWSER_BOOKMARK_TITLE_MATCH_H_