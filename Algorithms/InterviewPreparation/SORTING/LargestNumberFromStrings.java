import java.util.*;

class CompareStrings implements Comparator<String> {
        @Override
        public int compare(String X, String Y){
            //custom comparator function to compare two strings
            String XY = X+Y;
            String YX = Y+X;
            return XY.compareTo(YX) > 0? -1:1;
        }
}

class LargestNumberFromStrings{
    public static void main(String[] args){
        ArrayList<String> arr = new ArrayList<String>();
        arr.add("1000");
        arr.add("9");
        arr.add("89");
        arr.add("95");

        CompareStrings compareStrings = new CompareStrings();
        Collections.sort(arr, compareStrings);
        Iterator it = arr.iterator();
        while(it.hasNext()){
            System.out.print(it.next());
        }
    }
}
