package bg.sofia.uni.fmi.mjt.gameplatform.store.item.filter;

import bg.sofia.uni.fmi.mjt.gameplatform.store.item.StoreItem;

import java.time.LocalDateTime;

public class ReleaseDateItemFilter implements ItemFilter {
    private LocalDateTime lowerBound;
    private LocalDateTime upperBound;

    public ReleaseDateItemFilter(LocalDateTime lowerBound, LocalDateTime upperBound) {
        this.lowerBound = lowerBound;
        this.upperBound = upperBound;
    }

    @Override
    public boolean matches(StoreItem item) {
        LocalDateTime releaseDate = item.getReleaseDate();

        if (releaseDate == null) {
            return false;
        }

        return (releaseDate.isEqual(lowerBound) || releaseDate.isAfter(lowerBound)) &&
                (releaseDate.isEqual(upperBound) || releaseDate.isBefore(upperBound));
    }
}
