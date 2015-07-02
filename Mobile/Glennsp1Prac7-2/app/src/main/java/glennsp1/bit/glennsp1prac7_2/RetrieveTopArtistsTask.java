package glennsp1.bit.glennsp1prac7_2;

import android.os.AsyncTask;
import android.support.v4.app.Fragment;

import java.io.BufferedInputStream;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.net.HttpURLConnection;
import java.net.URL;
import java.util.ArrayList;

/**
 * Created by glenn_000 on 28-Apr-15.
 */
public class RetrieveTopArtistsTask {

    private final static String mApiKey = "&api_key=e7a051ce493831e8ab39d22ef91ae34e";
    private final static String mBaseUrl = "http://ws.audioscrobbler.com/2.0/";
    private final static String mArtistSearch = "?method=chart.gettopartists";
    private final static String mFormat = "&format=json";

    Fragment mFragment;
    public ArrayList<ArtistData> mArtistList;

    OnTaskResultListener taskListener;
    public interface OnTaskResultListener { public void onResult(ArrayList<ArtistData> artists); }

    public RetrieveTopArtistsTask(Fragment fragment) {
        this.mFragment = fragment;
        connectListener();

        String queryUrl = mBaseUrl + mArtistSearch + mApiKey + mFormat;
        new getTopArtistsTask().execute(queryUrl);
    }

    private void connectListener() {
        try {
            taskListener = (OnTaskResultListener) mFragment;
        } catch (ClassCastException e) {
            throw new ClassCastException("Class must implement OnTaskListener");
        }
    }

    private String readStream(InputStream in) throws IOException {

        BufferedReader reader = null;
        String result = "";
        try {
            reader = new BufferedReader(new InputStreamReader(in));
            String line;
            while ((line = reader.readLine()) != null) {
                result += line;
            }
        } catch (IOException e) {
            e.printStackTrace();
        } finally {
            if (reader != null) {
                try {
                    reader.close();
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
        }

        return result;
    }//End readStream

    class getTopArtistsTask extends AsyncTask<String, Void, String> {

        @Override
        protected String doInBackground(String... params) {

            String result = "";

            try {
                URL url = new URL(params[0]);
                HttpURLConnection urlConnection = (HttpURLConnection)url.openConnection();

                InputStream in = new BufferedInputStream(urlConnection.getInputStream());
                result = readStream(in);
            }
            catch (Exception e) {
                e.printStackTrace();
            }
            return result;
        }

        @Override
        protected void onPostExecute(String result) {
            ArtistJsonParser parser = new ArtistJsonParser();
            mArtistList = parser.readTopArtistsData(result);
            taskListener.onResult(mArtistList);
        }
    }

}
