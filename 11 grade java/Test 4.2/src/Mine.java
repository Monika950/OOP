import java.util.concurrent.Semaphore;
import java.util.concurrent.atomic.AtomicInteger;

class Mine {
    private AtomicInteger resources;
    private final Semaphore semaphore;

    public Mine(int resourceCount, int maxMiners) {
        this.resources = new AtomicInteger(resourceCount);
        this.semaphore = new Semaphore(maxMiners);
    }

    public boolean enterMine() throws InterruptedException {
        semaphore.acquire();
        return resources.get() > 0;
    }

    public void mineResources(Miner miner) {
        if (resources.get() > 0) {
            int mined = (int) (Math.random() * 10) + 1;
            mined = Math.min(mined, resources.get());
            resources.addAndGet(-mined);
            miner.addMinedResources(mined);
            System.out.println(miner.getName() + " mined " + mined + " resources. Remaining: " + resources);
        }
    }

    public void exitMine() {
        semaphore.release();
    }
}