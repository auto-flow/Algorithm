public class DiffAbs {
    public int countDistinctAbs(int[] nums) {
        if (nums == null || nums.length == 0) {
            return -1;
        }
        int i = 0;
        int j = nums.length - 1;
        int count = 0;
        while (i < j) {
            // 左指针相等
            if (i < nums.length - 1 && nums[i] == nums[i + 1]) {
                i++;
            }
            // 右指针相等
            if (j > 1 && nums[j] == nums[j - 1]) {
                j--;
            }
            // 同一个数
            if (nums[i] + nums[j] == 0) {
                i++;
                j--;
                count++;
            } else if (nums[i] + nums[j] > 0) {
                j--;
                count++;
            } else if (nums[i] + nums[j] < 0) {
                i++;
                count++;
            }
        }
        if (i == j) {
            count++;
        }
        return count;
    }

    public static void main(String[] args) {
        int ans=new DiffAbs().countDistinctAbs(new int[]{-3, -1, 0, 0, 2, 3, 5});
        System.out.println(ans);
    }
}
