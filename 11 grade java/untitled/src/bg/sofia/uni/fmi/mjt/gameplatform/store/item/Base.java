package bg.sofia.uni.fmi.mjt.gameplatform.store.item;

import java.math.BigDecimal;
import java.time.LocalDateTime;
import java.util.ArrayList;
import java.util.List;

public abstract class Base implements StoreItem  {
    private String title;
    private BigDecimal price;
    private LocalDateTime releaseDate;
    private List<Double> rating;

    public Base(String title, BigDecimal price, LocalDateTime releaseDate) {
        this.title = title;
        this.price = price;
        this.releaseDate = releaseDate;
        this.rating = new ArrayList<>();
    }

    @Override
    public String getTitle() {
        return this.title;
    }

    @Override
    public BigDecimal getPrice() {
        return this.price;
    }

    @Override
    public LocalDateTime getReleaseDate() {
        return this.releaseDate;
    }

    @Override
    public void setTitle(String title) {
        this.title = title;
    }

    @Override
    public void setPrice(BigDecimal price) {
        this.price = price;
    }

    @Override
    public void setReleaseDate(LocalDateTime releaseDate) {
        this.releaseDate = releaseDate;
    }

    @Override
    public double getRating() {
//        for (Double rating : this.rating) {
//            sum += rating;
//        }
        return rating.stream().reduce(0d, Double::sum) / rating.size();
    }

    @Override
    public void rate(double rating) {
        this.rating.add(rating);
    }
}
