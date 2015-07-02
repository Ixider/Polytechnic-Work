package glennsp1.bit.teleporter;

import android.content.Context;
import android.location.Criteria;
import android.location.LocationManager;
import android.location.Location;
import android.os.AsyncTask;
import android.support.v7.app.ActionBarActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.TextView;

import com.google.android.gms.maps.CameraUpdateFactory;
import com.google.android.gms.maps.GoogleMap;
import com.google.android.gms.maps.MapFragment;
import com.google.android.gms.maps.model.LatLng;

import org.apache.http.HttpResponse;
import org.apache.http.client.methods.HttpGet;
import org.apache.http.impl.client.DefaultHttpClient;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.text.DecimalFormat;
import java.util.Random;


public class Main_Activity extends ActionBarActivity {

    private GoogleMap map;

    private Random rGen;

    private static final int LATITUDE = 90;
    private static final int LONGITUDE = 180;
    private static final DecimalFormat DISPLAY_FORMAT = new DecimalFormat("0.000");

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main_);

        rGen = new Random();
        findViewById(R.id.teleportButton).setOnClickListener(onTeleportClick);

        configureMap();
    }

    private void configureMap() {
        map = ((MapFragment)getFragmentManager().findFragmentById(R.id.map)).getMap();
        map.getUiSettings().setZoomControlsEnabled(true);
    }

    private PositionalData getPhonePosition()  {
        LocationManager locationManager = (LocationManager)getSystemService(Context.LOCATION_SERVICE);

        Criteria defaultCriteria = new Criteria();

        String provider = locationManager.getBestProvider(defaultCriteria, false);

        Location currentLocation = locationManager.getLastKnownLocation(provider);

        PositionalData pData = new PositionalData();
        pData.Lat = currentLocation.getLatitude();
        pData.Lng = currentLocation.getLongitude();

        return pData;
    }

    private View.OnClickListener onTeleportClick = new View.OnClickListener() {

        @Override
        public void onClick(View v) {
            PositionalData data = getPhonePosition();
            double lat = data.Lat;
            double lon = data.Lng;

            moveCamera(lat, lon);

            Double[] geoPluginParams = { lon, lat };
            CallGeoPlugin callGeoPlugin = new CallGeoPlugin();
            callGeoPlugin.execute(geoPluginParams);

            setLongitudeDisplay(String.valueOf(DISPLAY_FORMAT.format(lon)));
            setLatitudeDisplay(String.valueOf(DISPLAY_FORMAT.format(lat)));
        }
    };

    private void moveCamera(double lat, double lon) {
        map.moveCamera(CameraUpdateFactory.newLatLng(new LatLng(lat, lon)));
        map.animateCamera(CameraUpdateFactory.zoomTo(15));
    }

    private void setLatitudeDisplay(String str) { ((TextView) findViewById(R.id.latDisplay)).setText(str); }
    private void setLongitudeDisplay(String str) { ((TextView) findViewById(R.id.longDisplay)).setText(String.valueOf(str)); }

    @Deprecated
    private double computeCoordinate(int value) {
        double coOrd =  rGen.nextDouble() * value;

        if(rGen.nextBoolean())
            coOrd *= -1;

        return coOrd;
    }


    private class CallGeoPlugin extends AsyncTask<Double, Void, String> {

        @Override
        protected String doInBackground(Double... params) {

            String result = "";
            double lat = params[0];
            double lng = params[1];

            String queryString = "http://www.geoplugin.net/extras/location.gp?lat="+ DISPLAY_FORMAT.format(lat) +"&long="  + DISPLAY_FORMAT.format(lng) + "&format=json";


            DefaultHttpClient client = new DefaultHttpClient();
            HttpGet httpGet = new HttpGet(queryString);

            try {
                HttpResponse response = client.execute(httpGet);
                InputStreamReader in = new InputStreamReader(response.getEntity().getContent());

                BufferedReader bufferedReader = new BufferedReader(in);

                result = "";

                String line = "";
                while ((line = bufferedReader.readLine()) != null) {
                    result += line;
                }

            } catch (Exception e) {
                e.printStackTrace();
            }

            return result;
        }

        @Override
        protected void onPostExecute(String s) {
            GeoPluginResultParser parser = new GeoPluginResultParser();

            String  result = parser.readLocation(s);

            ((TextView)findViewById(R.id.placeDisplay)).setText(result);
        }

    }

}
