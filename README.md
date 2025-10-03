# LeetCode Prep & Solutions

Solutions and study notes for algorithmic problems (LeetCode-focused), organized by topic/day and implemented primarily in C++ (with some other languages as applicable).  
_Last updated: **2025-10-03**._

## Repository Structure
The tree below hides files/folders ignored by `.gitignore` and limits depth for readability.

```text
leetcode_repo/
├── .gitignore
└── easy/
    ├── 0001_two_sum.cpp
    ├── 0020_valid_parentheses.cpp
    ├── 0021_merge_two_sorted_list.cpp
    ├── 0121_best_time_to_buy_and_sell_stock.cpp
    ├── 0232_implement_queue_using_stacks.cpp
    ├── 1114_print_in_order.cpp
└── medium/
    ├── 0003_longest_substring_without_repeating_characters.cpp
    ├── 0015_3Sum.cpp
    ├── 0033_search_in_rotated_sorted_array.cpp
    ├── 0049_group_anagrams.cpp
    ├── 0053_maximum_subarray.cpp
    ├── 0146_LRU_cache.cpp
    ├── 0155_min_stack.cpp
    ├── 0238_product_of_array_except_self.cpp
    ├── 0347_top_k_frequent_elements.cpp
    ├── 0743_network_delay_time.cpp
    ├── 1115_print_foobar_alternately.cpp
└── hard/
    ├── 0004_median_of_two_sorted_arrays.cpp
    ├── 0023_merge_k_sorted_list.cpp
    ├── 0239_sliding_window_maximum.cpp
    ├── 0295_find_median_from_data_stream.cpp

```

## 📊 Summary

- **Total solution files:** 8
- **Languages used:** C++ (8)
- **Unique LeetCode problem numbers detected:** 8

## 🚀 How to Run

### C++
```bash
# Single file
g++ -std=c++17 -O2 -Wall -Wextra path/to/file.cpp -o run && ./run
```

> Adjust paths and main method signatures as needed. Many files are written for the LeetCode runner; you can see that I write a main function for them to run locally.
> Tip: for competitive-style one-file builds, prefer a single translation unit per run.  
> If you have a `tasks.json` in `.vscode/`, use the **Build & Debug Active File** task.

## Problem Index

### Easy (6)
| No. | Title | File |
|---:|---|---|
| 1   | Two Sum | `easy/0001_two_sum.cpp` |
| 20  | Valid Parentheses | `easy/0020_valid_parentheses.cpp` |
| 21  | Merge Two Sorted Lists | `easy/0021_merge_two_sorted_lists.cpp` |
| 121 | Best Time to Buy and Sell Stock | `easy/0121_best_time_to_buy_and_sell_stock.cpp` |
| 232 | Implement Queue using Stacks | `easy/0232_implement_queue_using_stacks.cpp` |
| 1114 | Print in Order | `easy/1114_print_in_order.cpp` |

### Medium (11)
| No. | Title | File |
|---:|---|---|
| 3   | Longest Substring Without Repeating Characters | `medium/0003_longest_substring_without_repeating_characters.cpp` |
| 15  | 3Sum | `medium/0015_3Sum.cpp` |
| 33  | Search in Rotated Sorted Array | `medium/0033_search_in_rotated_sorted_array.cpp` |
| 49  | Group Anagrams | `medium/0049_group_anagrams.cpp` |
| 53  | Maximum Subarray | `medium/0053_maximum_subarray.cpp` |
| 146 | LRU Cache | `medium/0146_LRU_cache.cpp` |
| 155 | Min Stack | `medium/0155_min_stack.cpp` |
| 238 | Product of Array Except Self | `medium/0238_product_of_array_except_self.cpp` |
| 347 | Top K Frequent Elements | `medium/0347_top_k_frequent_elements.cpp` |
| 743 | Network Delay Time | `medium/0743_network_delay_time.cpp` |
| 1115 | Print FooBar Alternately | `medium/1115_print_foobar_alternately.cpp` |

### Hard (4)
| No. | Title | File |
|---:|---|---|
| 4   | Median of Two Sorted Arrays | `hard/0004_median_of_two_sorted_arrays.cpp` |
| 23  | Merge k Sorted Lists | `hard/0023_merge_k_sorted_list.cpp` |
| 239 | Sliding Window Maximum | `hard/0239_sliding_window_maximum.cpp` |
| 295 | Find Median from Data Stream | `hard/0295_find_median_from_data_stream.cpp` |


> _Tip:_ Keep file names as \`####-problem-slug.ext\` (e.g., \`0053-maximum-subarray.cpp\`) to enable clean linking.
