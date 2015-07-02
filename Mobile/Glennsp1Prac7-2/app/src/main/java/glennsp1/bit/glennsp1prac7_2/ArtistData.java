package glennsp1.bit.glennsp1prac7_2;

import android.graphics.Bitmap;
import android.widget.ImageView;

/**
 * Created by glenn_000 on 27-Apr-15.
 */
public class ArtistData {

    public String Name;
    public String Url;
    public String ImageUrl;
    public Bitmap Image;


    public ArtistData(String name, String url, String imageUrl) {
        Name = name;
        Url = url;
        ImageUrl = imageUrl;
    }
}
