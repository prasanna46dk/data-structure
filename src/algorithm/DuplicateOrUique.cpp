#include<iostream>
#include<time.h>
#include<cstdlib>
#include<map>
#include<vector>
#include<unordered_set>
#include<iterator>

using namespace std;

#define MAX_TRANSACTION_RECORDS 10
#define MAX_TIME_RECORDS 10
#define HOUR 60*60*60


/* Given tuple of transaction_time and transaction_id write a program
 * to find duplicates/unique transaction ids and if transaction time is
 * older than 1 hr then provide a mechanism to purge the records
 *
 * Assumption: transaction is a map of time and list if transaction_ids
 */
void isDuplicateOrUnique(map<time_t, vector<long>> &transaction) {
    unordered_set<long> tranc_ids;
    for (auto itr = transaction.begin();
         itr != transaction.end();
         itr++) {
        time_t cur_time = time(NULL);
        // check if time of a transactions is more than 1 hour old
        // if yes delete the record.
        if (itr->first < (cur_time - HOUR))
            transaction.erase(itr->first);
        else {
            for (auto tranc_id: itr->second) {
                if (tranc_ids.find(tranc_id) != tranc_ids.end())
                    cout << "Duplicate" << endl;
                else 
                    cout << "Unique" << endl;
                tranc_ids.insert(tranc_id);
            }
        }
    }
}

void transaction_gen(map<time_t, vector<long>> &trac) {
    for (int i = 0; i < MAX_TIME_RECORDS; i++) {
        long j = 0;
        vector<long> transaction_id;
        srand(65535);
        while(j < MAX_TRANSACTION_RECORDS) {
            long test = rand();
            transaction_id.push_back(test);
            transaction_id.push_back(test);
            j++;
        }
        srand(time(0));
        time_t t = rand();
        trac.insert(pair<time_t, vector<long>>(t, transaction_id));
    }
}

int main() 
{
    map<time_t, vector<long>> transaction;
    transaction_gen(transaction);
    isDuplicateOrUnique(transaction);
    return 0; 
}
