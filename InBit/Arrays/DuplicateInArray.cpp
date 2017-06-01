https://www.interviewbit.com/problems/find-duplicate-in-array/

public class Solution {
	// DO NOT MODIFY THE LIST
	private int[] buckets;

    private int AVG_BUCKET_SIZE = 0;

    private int LAST_BUCKET_SIZE = 0;

    // DO NOT MODIFY THE LIST
    public int repeatedNumber(final List<Integer> A) {
        int n = A.size() - 1; // [1 : n] for (n + 1) number
        if (n < 1) {
            // no way to find duplicates
            return -1;
        }
        int nBuckets = (int) Math.ceil(Math.sqrt(n)); // ceiling of sqrt(n)
        int range = (int) Math.sqrt(n); // floor of sqrt(n)

        buckets = new int[nBuckets];
        if (range * nBuckets < n) {
            // enlarge range of each bucket to contain all elements
            range++;
        }

        LAST_BUCKET_SIZE = n - (nBuckets - 1) * range;

        AVG_BUCKET_SIZE = range;

        int targetBucket = -1;
        for (int num : A) {
            int iBucket = (num - 1) / range;
            buckets[iBucket]++;
            if (moreThanExpected(iBucket)) {
                // once we found a bucket holding more elements than expected
                targetBucket = iBucket;
                break;
            }
        }
        if (targetBucket != -1) {
            Set<Integer> targetSet = new HashSet<>();
            int lower = targetBucket * range + 1;
            int upper = lower + range - 1;
            for (int num : A) {
                if (num >= lower && num <= upper && !targetSet.add(num)) {
                    // duplicate found
                    return num;
                }
            }
        }
        return -1;
    }

    // whether bucket[n] has more than expected elements
    private boolean moreThanExpected(int nBucket) {
        if (nBucket == buckets.length - 1) {
            return buckets[nBucket] > LAST_BUCKET_SIZE;
        } else {
            return buckets[nBucket] > AVG_BUCKET_SIZE;
        }
    }

}
