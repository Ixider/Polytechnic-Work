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

public class RetrieveSearchTask {
    private final static String mApiKey = "&api_key=e7a051ce493831e8ab39d22ef91ae34e";
    private final static String mBaseUrl = "http://ws.audioscrobbler.com/2.0/";
    private final static String mArtistSearch = "?method=artist.search&artist=";
    private final static String mFormat = "&format=json";

    Fragment fragment;

    OnTaskResultListener taskListener;
    public interface OnTaskResultListener { public void onResult(ArrayList<ArtistData> artists); }

    public ArrayList<ArtistData> mArtistList;

    public RetrieveSearchTask(Fragment fragment) {
        this.fragment = fragment;
        connectListener();
    }

    private void connectListener() {
        try {
            taskListener = (OnTaskResultListener)fragment;
        } catch (ClassCastException e) {
            throw new ClassCastException("Class must implement OnTaskListener");
        }
    }

    public void Search(String input) {
        String queryUrl = mBaseUrl + mArtistSearch + input + mApiKey + mFormat;
        new SearchTask().execute(queryUrl);
    }//End Search

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


    class SearchTask extends AsyncTask<String, Void, String> {

        @Override
        protected String doInBackground(String[] params) {
            String queryString = params[0];
            String result = "";

            try {
                URL url = new URL(queryString);
                HttpURLConnection urlConnection = (HttpURLConnection)url.openConnection();

                InputStream in = new BufferedInputStream(urlConnection.getInputStream());
                result = readStream(in);

            } catch (Exception e) {
                e.printStackTrace();
            }

            return result;
        }//End doInBackground

        @Override
        protected void onPostExecute(String json) {
            ArtistJsonParser parser = new ArtistJsonParser();
            mArtistList = parser.readSearchData(json);
            taskListener.onResult(mArtistList);
        }//End onPostExecute
    }//End SearchTask

}//End DataFactory

