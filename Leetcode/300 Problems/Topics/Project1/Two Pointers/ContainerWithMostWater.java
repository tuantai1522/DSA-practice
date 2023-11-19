public class ContainerWithMostWater {
    public static int maxArea(int[] heights) {
        int length = heights.length;

        int left = 0;
        int right = length - 1;

        int result = -1;

        while(left < right){
            int width = Math.min(heights[left], heights[right]);
            int height = Math.abs(right - left);

            int countArea = width * height;

            result = Math.max(result, countArea);

            if(heights[left] < heights[right]){
                ++left;
            }else if(heights[left] > heights[right]){
                --right;
            }else{
                ++left;
                --right;
            }

        }
        return result;
    }

    public static void main(String[] args) {
        int [] array = {1,8,6,2,5,4,8,3,4};

        int result = maxArea(array);
        System.out.println(result);
    }
}
