import java.lang.reflect.Method;
import java.util.HashMap;
import java.util.concurrent.atomic.AtomicInteger;

public class TestReflection{

    public static void main(String[] args) throws ClassNotFoundException {
//        LRUCache cache = new LRUCache(2);
//        Class LRUClass = cache.getClass();
//        Method[] methods = LRUClass.getDeclaredMethods();
//        for(Method m: methods)
//            System.out.println(m);
        AtomicInteger atomicInteger = new AtomicInteger();
        System.out.println(atomicInteger.hashCode());
        System.out.println(atomicInteger.hashCode());
        HashMap<Integer, Integer> map = new HashMap<>();
        System.out.println(map.containsKey(null));


    }
}