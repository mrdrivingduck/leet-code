/**
 * @author Mr Dk.
 * @version 2021/01/18
 */

/*
    Given a list accounts, each element accounts[i] is a list of strings,
    where the first element accounts[i][0] is a name, and the rest of the
    elements are emails representing emails of the account.

    Now, we would like to merge these accounts. Two accounts definitely
    belong to the same person if there is some email that is common to both
    accounts. Note that even if two accounts have the same name, they may
    belong to different people as people could have the same name. A person
    can have any number of accounts initially, but all of their accounts
    definitely have the same name.

    After merging the accounts, return the accounts in the following format:
    the first element of each account is the name, and the rest of the
    elements are emails in sorted order. The accounts themselves can be
    returned in any order.

    Example 1:
        Input: 
            accounts = [["John", "johnsmith@mail.com", "john00@mail.com"], ["John", "johnnybravo@mail.com"], ["John", "johnsmith@mail.com", "john_newyork@mail.com"], ["Mary", "mary@mail.com"]]
        Output:
            [["John", 'john00@mail.com', 'john_newyork@mail.com', 'johnsmith@mail.com'],  ["John", "johnnybravo@mail.com"], ["Mary", "mary@mail.com"]]
        Explanation: 
            The first and third John's are the same person as they have the common email "johnsmith@mail.com".
            The second John and Mary are different people as none of their email addresses are used by other accounts.
            We could return these lists in any order, for example the answer [['Mary', 'mary@mail.com'], ['John', 'johnnybravo@mail.com'], 
            ['John', 'john00@mail.com', 'john_newyork@mail.com', 'johnsmith@mail.com']] would still be accepted.

    Note:
        The length of accounts will be in the range [1, 1000].
        The length of accounts[i] will be in the range [1, 10].
        The length of accounts[i][j] will be in the range [1, 30].

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/accounts-merge
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

/*
    我只是觉得很无语，做法居然这么传统。

    首先筛出所有 unique 的 email，并依次赋予一个编号；同时，维护 email 与用户名的映射关系。
    对每一个用户下的所有 email，根据 email 的编号，通过并查集，进行合并。
    最终将每个 email 组赋予给一个用户，用户的姓名通过任意一个 email 从映射关系中获得。
 */

#include <cassert>

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::unordered_map;

class Solution {
private:
    int find(vector<int> &collection, int index) {
        if (collection[index] != index) {
            collection[index] = find(collection, collection[index]);
        }

        return collection[index];
    }

public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string, int> email_id_map;
        unordered_map<string, int>::iterator email_id_map_iter;
        unordered_map<string, string> email_name_map;
        
        // <email, username>
        // <email, email_id>
        int email_count = 0;
        for (size_t i = 0; i < accounts.size(); i++) {
            // emails start from index 1.
            for (size_t j = 1; j < accounts[i].size(); j++) {
                email_id_map_iter = email_id_map.find(accounts[i][j]);
                if (email_id_map_iter == email_id_map.end()) {
                    email_id_map.insert(
                        std::pair<string, int>(accounts[i][j], email_count++));
                    email_name_map.insert(
                        std::pair<string, string>(accounts[i][j], accounts[i][0]));
                }
            }
        }

        // disjoint set (by email_id).
        vector<int> email_collection(email_count);
        for (size_t i = 0; i < email_collection.size(); i++) {
            email_collection[i] = i;
        }
        // merge email from the same user.
        for (size_t i = 0; i < accounts.size(); i++) {
            int head_email_id = email_id_map.find(accounts[i][1])->second;
            for (size_t j = 2; j < accounts[i].size(); j++) {
                int email_id = email_id_map.find(accounts[i][j])->second;
                email_collection[find(email_collection, email_id)]
                        = find(email_collection, head_email_id);
            }
        }

        // <email_id, [emails]>
        unordered_map<int, vector<string>> id_email_map;
        unordered_map<int, vector<string>>::iterator id_email_map_iter;
        for (email_id_map_iter = email_id_map.begin();
                email_id_map_iter != email_id_map.end();
                email_id_map_iter++) {
            int root_email_id = find(email_collection, email_id_map_iter->second);
            id_email_map_iter = id_email_map.find(root_email_id);
            if (id_email_map_iter == id_email_map.end()) {
                vector<string> user_emails = { email_id_map_iter->first };
                id_email_map.insert(
                    std::pair<int, vector<string>>(root_email_id, user_emails));
            } else {
                id_email_map_iter->second.push_back(email_id_map_iter->first);
            }
        }

        // <email_id, [emails]> --> [ user_name, [emails] ]
        vector<vector<string>> result;
        for (id_email_map_iter = id_email_map.begin();
                id_email_map_iter != id_email_map.end();
                id_email_map_iter++) {
            vector<string> emails = id_email_map_iter->second;
            string first_email = emails[0];
            string user = email_name_map.find(first_email)->second;
            std::sort(emails.begin(), emails.end());
            vector<string> single_user = { user };
            single_user.insert(single_user.end(), emails.begin(), emails.end());
            result.push_back(single_user);
        }

        return result;
    }
};

int main()
{
    Solution s;
    vector<vector<string>> accounts;
    vector<vector<string>> unique_accounts;

    accounts = {
        { "John", "johnsmith@mail.com", "john00@mail.com" },
        { "John", "johnnybravo@mail.com" },
        { "John", "johnsmith@mail.com", "john_newyork@mail.com" },
        { "Mary", "mary@mail.com" }
    };
    unique_accounts = {
        { "John", "johnnybravo@mail.com" },
        { "John", "john00@mail.com", "john_newyork@mail.com", "johnsmith@mail.com" },
        { "Mary", "mary@mail.com" }
    };
    assert(unique_accounts == s.accountsMerge(accounts));

    return 0;
}
