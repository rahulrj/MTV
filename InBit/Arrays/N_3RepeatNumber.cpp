https://www.interviewbit.com/problems/n3-repeat-number/

class Solution {
    public:
        struct eleCount {
            int e; // Element
            int c; // Count
        }
        int repeatedNumber(const vector<int> &V) {
            if (V.size() == 0) return -1;

            /* Step 1: Create a temporary array (contains element
               and count) of size 2. Initialize count of all
               elements as 0 */
            struct eleCount temp[2];
            temp[0].c = temp[1].c = 0;

            /* Step 2: Process all elements of input array */
            for (int i = 0; i < V.size(); i++) {
                int j;

                /* If arr[i] is already present in
                   the element count array, then increment its count */
                if (temp[0].e == arr[i] || temp[1] == arr[i]) {
                    if (temp[0].e == arr[i]) temp[0].c += 1;
                    else temp[1].c += 1;
                } else {
                /* If arr[i] is not present in temp[] */
                    int l;

                    /* If there is position available in temp[], then place
                       arr[i] in the first available position and set count as 1*/
                    if (temp[0].c == 0 || temp[1].c == 0) {
                        int index = (temp[0].c == 0) ? 0 : 1;
                        temp[index].e = arr[i];
                        temp[index].c = 1;
                    } else {
                    /* If all the position in the temp[] are filled, then
                       decrease count of every element by 1 */
                        temp[0].c -= 1;
                        temp[1].c -= 1;
                    }
                }
            }

            /*Step 3: Check actual counts of potential candidates in temp[]*/
            for (int i = 0; i < 2; i++) {
                // Calculate actual count of elements
                int ac = 0;  // actual count
                for (int j = 0; j < n; j++)
                    if (arr[j] == temp[i].e)
                        ac++;

                // If actual count is more than n/k, then print it
                if (ac > V.size() / 3) return temp[i].e;
            }
            // Not found
            return -1;
        }
};
