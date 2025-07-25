import java.util.*;
import java.io.*;

public class Test {
    public static void main(String[] args) throws IOException {
        List<Integer> list = new ArrayList<>();

        list.add(1);
        list.add(2);
        list.add(3);

        System.out.println(list);

        ListIterator<Integer> iterator = list.listIterator();

        while (iterator.hasNext()) {
            int value = iterator.next();
            if (value == 2) {
                System.out.println(iterator.previousIndex());
                iterator.set(4);
            }
        }

        System.out.println(list);
    }
}
