import java.util.*;

class Median{
    public double MedianOfDifferentSizedArrays2(int[] a, int[] b){
        //This approach takes O(M+N) time complexity
        //Idea is to take care of middle elements while merging sorted arrays
        //Here we do not need to actually merge but simply count while merging
        int sz = a.length+b.length;
        int i = 0, j = 0, k = 0;
        double median = 0;
        while (i < a.length || j < b.length){
            int current = 0;
            if(i < a.length && j < b.length){
                if(a[i] <= b[j]){
                    ++k; ++i;
                }
                else {
                    ++k; current = 1; ++j;
                }
            }
            else if(i < a.length){
                ++k; ++i;
            }
            else if(j < b.length){
                ++k; current = 1; ++j;
            }
            //System.out.println(i+" "+j);
            if(sz % 2 == 0){
                int mid = sz/2;
                if(k == mid || k == (mid+1)){
                    if(current == 0)
                        median += a[i-1];
                    else median += b[j-1];
                }
                if(k == (mid+1)){
                    median /= 2;
                    break;
                }
            }
            else{
                int mid = (sz+1)/2;
                if(k == mid){
                    if(current == 0)
                        median += a[i-1];
                    else median += b[j-1];
                    break;
                }
            }
        }
        return median;
    }

    public double MedianOfDifferentSizedArrays(int[] a, int[] b) {
        //idea is to partition combined array into two equal parts
        //Time complexity is O(log(min(M,N)) and space complexity is O(1)
        int sz = a.length + b.length + 1; //size of combined array (+1 is to make sure left array has greater elements in case of odd sum)
        int start = 0, end = a.length;
        double median = 0;
        while (start <= end) {
            //traverse one of the arrays to apply binary search
            int partitionX = (start + end) / 2;
            int partitionY = sz / 2 - partitionX;
            int maxLeftX = (partitionX == 0) ? Integer.MIN_VALUE : a[partitionX - 1];
            int minRightX = (partitionX == a.length) ? Integer.MAX_VALUE : a[partitionX];
            int maxLeftY = (partitionY == 0) ? Integer.MIN_VALUE : b[partitionY - 1];
            int minRightY = (partitionY == b.length) ? Integer.MAX_VALUE : b[partitionY];
            //System.out.println(maxLeftX+" "+minRightX+" "+maxLeftY+" "+minRightY);
            //If the required criteria (for median) is satisfied
            if (maxLeftX <= minRightY && maxLeftY <= minRightX) {
                if ((a.length + b.length) % 2 == 0)
                    median = (double) (Math.max(maxLeftX, maxLeftY) + Math.min(minRightX, minRightY)) / 2;
                else
                    median = (double) Math.max(maxLeftX, maxLeftY);
                break;
            }

            if (maxLeftX > minRightY)
                end = partitionX - 1;
            else if (maxLeftY > maxLeftX)
                start = partitionX + 1;

        }
        return median;
    }
}

class MedianSortedArrays{
    public static void main(String[] args){
        int[] a = new int[]{1,2,5,6,9,10};
        int[] b = new int[]{3,4,7,8};
        Median obj = new Median();
        if(a.length <= b.length)
            System.out.println(obj.MedianOfDifferentSizedArrays2(a,b));
        else
            System.out.println(obj.MedianOfDifferentSizedArrays2(b,a));
    }
}
