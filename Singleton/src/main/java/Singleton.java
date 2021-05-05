public class Singleton {
    private volatile static Singleton uniqueInstance;

    private Singleton(){
        try {
            Thread.sleep(1000L);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    }

    public static Singleton getInstance(){
        if(uniqueInstance == null){
            synchronized (Singleton.class){
                if(uniqueInstance == null){
                    uniqueInstance = new Singleton();
                }
            }
        }
        return uniqueInstance;
    }

    public static Singleton getInstanceWithoutSynchronized(){
        if (uniqueInstance == null) {
            if (uniqueInstance == null) {
                uniqueInstance = new Singleton();
            }

        }
        return uniqueInstance;
    }
}
