package bg.sofia.uni.fmi.mjt.gameplatform.store.item;

import java.math.BigDecimal;
import java.time.LocalDateTime;

public class DLC extends Base implements StoreItem{
    private Game game;

    public DLC(String title, BigDecimal price, LocalDateTime releaseDate, Game game)
    {
        super(title, price, releaseDate);
        this.game = game;
    }
}
