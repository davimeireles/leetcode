import java.util.Arrays;

class TwoSum {
    public int[] twoSum(int[] nums, int target) {

        int []ret_index = new int[2];

        for (int i = 0; i < nums.length; i++) {
            for (int j = i + 1; j < nums.length; j++) {
                if (nums[i] + nums[j] == target) {
                    ret_index[0] = i;
                    ret_index[1] = j;
                    return ret_index;
                }
            }
        }
        return ret_index;
    }

    public static void main(String[] args) {
        TwoSum twoSum = new TwoSum();

        int[] nums_ex1 = {2, 7, 11, 15};
        int target_ex1 = 9;

        int[] nums_ex2 = {3,2,4};
        int target_ex2 = 6;

        int[] nums_ex3 = {3,3};
        int target_ex3 = 6;

        int[] res = twoSum.twoSum(nums_ex1, target_ex1);
        int[] res2 = twoSum.twoSum(nums_ex2, target_ex2);
        int[] res3 = twoSum.twoSum(nums_ex3, target_ex3);

        System.out.println("Index's: " + Arrays.toString(res));
        System.out.println("Index's: " + Arrays.toString(res2));
        System.out.println("Index's: " + Arrays.toString(res3));
    }
}




