package glennsp1.bit.thirdrdpartylibraries.GoogleMap;

import android.app.Activity;
import android.app.Fragment;
import android.app.FragmentManager;
import android.content.Context;
import android.location.Criteria;
import android.location.Location;
import android.location.LocationManager;
import android.os.Build;
import android.os.Bundle;
import android.support.annotation.Nullable;
import android.support.v4.app.FragmentActivity;
import android.util.Log;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.Button;

import com.google.android.gms.maps.CameraUpdateFactory;

import com.google.android.gms.maps.GoogleMap;
import com.google.android.gms.maps.MapFragment;
import com.google.android.gms.maps.SupportMapFragment;
import com.google.android.gms.maps.model.LatLng;

import java.util.Map;
import java.util.Random;

import glennsp1.bit.thirdrdpartylibraries.R;

/**
 * Created by S. Glenn on 10-May-15.
 */
public class FragmentGoogleMaps extends Fragment {

    private GoogleMap map;
    private Random rGen;
    private static final int LATITUDE = 90;
    private static final int LONGITUDE = 180;

    @Nullable
    @Override
    public View onCreateView(LayoutInflater inflater, ViewGroup container, Bundle savedInstanceState) {
        View v = inflater.inflate(R.layout.fragment_google_maps_layout, container, false);

        init(v);

        return v;
    }

    private void init(View v) {
        rGen = new Random();
        map = ((MapFragment)getFragmentManager().findFragmentById(R.id.map)).getMap();
        map.getUiSettings().setZoomControlsEnabled(true);

        Button teleportButton = (Button) v.findViewById(R.id.teleportButton);
        teleportButton.setOnClickListener(onTeleportClick);
    }

    private PositionalData getPhonePosition()  {
        LocationManager locationManager = (LocationManager)getActivity().getSystemService(Context.LOCATION_SERVICE);

        Criteria defaultCriteria = new Criteria();

        String provider = locationManager.getBestProvider(defaultCriteria, false);

        Location currentLocation = locationManager.getLastKnownLocation(provider);

        PositionalData pData = new PositionalData();
        pData.Lat = currentLocation.getLatitude();
        pData.Lon = currentLocation.getLongitude();

        return pData;
    }

    private View.OnClickListener onTeleportClick = new View.OnClickListener() {

        @Override
        public void onClick(View v) {
            double lat = computeCoordinate(LATITUDE);
            double lon = computeCoordinate(LONGITUDE);

            moveCamera(lon, lat);
        }
    };

    private void moveCamera(double lat, double lon) {
        map.moveCamera(CameraUpdateFactory.newLatLng(new LatLng(lat, lon)));
        map.animateCamera(CameraUpdateFactory.zoomTo(10));
    }

    private double computeCoordinate(int value) {
        double coOrd =  rGen.nextDouble() * value;

        if(rGen.nextBoolean())
            coOrd *= -1;

        return coOrd;
    }

    public class PositionalData {
        public double Lat;
        public double Lon;
    }
}
