package bg.sofia.uni.fmi.mjt.gameplatform.store.item;

import java.io.Serializable;
import java.math.BigDecimal;
import java.time.LocalDateTime;

public class GameBundle extends Base implements StoreItem{
    private Game[] games;

    public GameBundle(String title, BigDecimal price, LocalDateTime releaseDate, Game[] games)
    {
        super(title, price, releaseDate);
        this.games = games;
    }
}
