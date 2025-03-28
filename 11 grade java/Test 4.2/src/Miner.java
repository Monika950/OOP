class Miner extends Thread {
    private final Mine mine;
    private final String name;
    private int minedResources;
    private int entries;
    private static final int MAX_ENTRIES_BEFORE_REST = 3;

    public Miner(String name, Mine mine) {
        this.name = name;
        this.mine = mine;
        this.minedResources = 0;
        this.entries = 0;
    }

    public void addMinedResources(int amount) {
        minedResources += amount;
    }

    @Override
    public String getName() {
        return name;
    }

    @Override
    public void run() {
        try {
            while (mine.enterMine()) {
                System.out.println(name + " entered the mine.");
                mine.mineResources(this);
                mine.exitMine();
                entries++;

                if (entries % MAX_ENTRIES_BEFORE_REST == 0) {
                    System.out.println(name + " is resting...");
                    Thread.sleep((int) (Math.random() * 3000) + 1000);
                }
                Thread.sleep((int) (Math.random() * 2000) + 500);
            }
        } catch (InterruptedException e) {
            Thread.currentThread().interrupt();
        }
        System.out.println(name + " finished mining with total resources: " + minedResources);
    }
}