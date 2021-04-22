public class ContainerWithMostWater {
    
    public int maxArea(int[] height) {
        
        int p1 = 0;
        int p2 = height.length;
        int answer = 0;
        
        while (p1 < p2) {
            int minh = Math.min(height[p1], height[p2]);
            answer = Math.max(answer, (p2-p1)*minh);
            while (p1<p2 && height[p1] <= minh) {
                p1++;
            }
            while (p1<p2 && height[p2] <= minh){
                p2--;
            }
        }
        return answer;
    }
}
