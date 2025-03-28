public class MiningSimulation {
    public static void main(String[] args) {
        int totalResources = 100;
        int maxMinersAtOnce = 3;
        int numberOfMiners = 5;

        Mine mine = new Mine(totalResources, maxMinersAtOnce);
        Miner[] miners = new Miner[numberOfMiners];

        for (int i = 0; i < numberOfMiners; i++) {
            miners[i] = new Miner("Miner-" + (i + 1), mine);
            miners[i].start();
        }

        for (Miner miner : miners) {
            try {
                miner.join();
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
        System.out.println("Mining simulation complete.");
    }
}
