package glennsp1.bit.teleporter;

import org.json.JSONException;
import org.json.JSONObject;

/**
 * Created by glenn_000 on 21-Apr-15.
 */
public class GeoPluginResultParser {

    public GeoPluginResultParser() {

    }

    public String readLocation(String in) {

        JSONObject data = null;

        String location = "No Place Found";
        try {
            data = new JSONObject(in);
            location = data.getString("geoplugin_place");
        } catch (JSONException e) {
            e.printStackTrace();
        }

        return location;
    }
}
