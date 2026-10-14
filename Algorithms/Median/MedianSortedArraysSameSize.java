import java.util.*;

class MedianSameSize {

    public double medianFind(int[] a){
        int m = a.length;
        if(m%2 == 0)
            return (double)(a[m/2-1]+a[m/2])/2;
        else return a[m/2];
    }

    public double MedianSameSizeSortedArrays(int[] a, int[] b){
        //Divide and Conquer
        int len = a.length;
        if(len <= 0) return Integer.MIN_VALUE;
        if(len == 1) return (double)(a[0]+b[0])/2;
        if(len == 2) return (double)(Math.max(a[0], b[0])+Math.min(a[1], b[1]))/2;

        double m1 = medianFind(a);
        double m2 = medianFind(b);
        //System.out.println(m1+" "+m2);
        if(m1 < m2) {
            //median will be present in second half of a and first half of b
            if(len%2 == 0)
                return MedianSameSizeSortedArrays(Arrays.copyOfRange(a,len/2, len), Arrays.copyOfRange(b, 0, len/2));
            else
                return MedianSameSizeSortedArrays(Arrays.copyOfRange(a, len/2, len), Arrays.copyOfRange(b, 0, len/2+1));
        }
        else {
            //median will be present in first half of a and second half of b
            if(len%2 == 0)
                return MedianSameSizeSortedArrays(Arrays.copyOfRange(a, 0, len/2), Arrays.copyOfRange(b, len/2, len));
            else
                return MedianSameSizeSortedArrays(Arrays.copyOfRange(a, 0, len/2+1), Arrays.copyOfRange(b, len/2, len));
        }
    }

}

class MedianSortedArraysSameSize {
    public static void main(String[] args){
        //int[] a = new int[]{1,2,5,6,9,10};
        //int[] b = new int[]{3,4,7,8,11,12};
        //int[] a = new int[]{1,2,5,6,9,10,13};
        //int[] b = new int[]{3,4,7,8,11,12,14};
        //int[] a = new int[]{1,2};
        //int[] b = new int[]{3,4};
        int[] a = new int[]{1};
        int[] b = new int[]{3};
        MedianSameSize obj = new MedianSameSize();
        System.out.println(obj.MedianSameSizeSortedArrays(a,b));
    }
}
