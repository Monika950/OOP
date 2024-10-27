package bg.sofia.uni.fmi.mjt.gameplatform.store;

import bg.sofia.uni.fmi.mjt.gameplatform.store.item.StoreItem;
import bg.sofia.uni.fmi.mjt.gameplatform.store.item.filter.ItemFilter;

import java.math.BigDecimal;
import java.util.ArrayList;
import java.util.List;

public class GameStore implements StoreAPI {
    private StoreItem[] availableItems;

    public GameStore(StoreItem[] availableItems){
        this.availableItems = availableItems;
    }

    @Override
    public StoreItem[] findItemByFilters(ItemFilter[] itemFilters) {
        if (itemFilters == null || itemFilters.length == 0) {
            return availableItems;
        }

        List<StoreItem> filteredItems = new ArrayList<>();

        for (StoreItem item : availableItems) {
            boolean matchesAllFilters = true;

            for (ItemFilter filter : itemFilters) {
                if (!filter.matches(item)) {
                    matchesAllFilters = false;
                    break;
                }
            }

            if (matchesAllFilters) {
                filteredItems.add(item);
            }
        }

        return filteredItems.toArray(new StoreItem[0]);
    }

    private double getDiscount(String promoCode)
    {
        return switch (promoCode) {
            case "VAN40" -> 0.40;
            case "100YO" -> 1.00;
            default -> 0.0;
        };
    }

    @Override
    public void applyDiscount(String promoCode) {
        if(promoCode==null){
            return;
        }

        BigDecimal discountPercentage = BigDecimal.valueOf(getDiscount(promoCode));

        for(StoreItem item : availableItems){
            BigDecimal price = item.getPrice();
            BigDecimal discountAmount = price.multiply(discountPercentage);
            BigDecimal newPrice = price.subtract(discountAmount);

            item.setPrice(newPrice);
            //item.setPrice(item.getPrice().subtract(item.getPrice().multiply(BigDecimal.valueOf(getDiscount(promoCode)))));
        }
    }

    @Override
    public boolean rateItem(StoreItem item, int rating) {
        if (item == null || rating < 1 || rating > 5) {
            return false;
        }

        item.rate(rating);
        return true;
    }
}
