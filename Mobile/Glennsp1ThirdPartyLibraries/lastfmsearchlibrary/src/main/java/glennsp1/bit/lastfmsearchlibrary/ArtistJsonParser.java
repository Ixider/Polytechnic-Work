package glennsp1.bit.lastfmsearchlibrary;

import org.json.JSONArray;
import org.json.JSONException;
import org.json.JSONObject;

import java.util.ArrayList;

/**
 * Created by glenn_000 on 27-Apr-15.
 */
public class ArtistJsonParser {

    private String mResultsKey = "results";
    private String mArtistMatchesKey = "artistmatches";
    private String mArtistArrayKey = "artist";
    private String imageUrlArryKey = "image";
    private String nameField = "name";
    private String urlField = "url";
    private String imageArrayField = "image";

    public ArrayList<ArtistData> readSearchData(String in) {

        ArrayList<ArtistData> artistData = new ArrayList<>();

        JSONObject data = null;

        try {
            data = new JSONObject(in);
            JSONObject results = data.getJSONObject(mResultsKey);
            JSONObject artistsObj = results.getJSONObject(mArtistMatchesKey);
            JSONArray artists = artistsObj.getJSONArray(mArtistArrayKey);

           for(int i = 0; i < artists.length(); i++) {
               ArtistData artist = readArtist(artists.getJSONObject(i));
               artistData.add(artist);
           }

        } catch (JSONException e) {
            e.printStackTrace();
        }

        return artistData;
    }

    public ArrayList<ArtistData> readTopArtistsData(String in) {

        ArrayList<ArtistData> artistData = new ArrayList<>();

        JSONObject data = null;

        try {
            data = new JSONObject(in);
            JSONObject results = data.getJSONObject("artists");
            JSONArray artists = results.getJSONArray("artist");

            for(int i = 0; i < artists.length(); i++) {
                ArtistData artist = readArtist(artists.getJSONObject(i));
                artistData.add(artist);
            }

        } catch (JSONException e) {
            e.printStackTrace();
        }

        return artistData;
    }



    private ArtistData readArtist(JSONObject artist) throws JSONException {

        String name = artist.getString(nameField);
        String imageUrl = getImageUrl(artist.getJSONArray(imageArrayField));

        return new ArtistData(name, imageUrl);
    }

    private String getImageUrl(JSONArray imageUrls) throws JSONException {

        String url = "";
        for(int i = 0; i < imageUrls.length(); i++) {
            JSONObject image = imageUrls.getJSONObject(i);

            String size = image.getString("size");
            if(size.equals("medium")) {
                url = image.getString("#text");
            }
        }

        return url;
    }
}
