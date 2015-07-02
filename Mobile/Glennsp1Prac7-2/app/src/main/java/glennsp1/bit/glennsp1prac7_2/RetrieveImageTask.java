package glennsp1.bit.glennsp1prac7_2;

import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.os.AsyncTask;
import android.widget.ImageView;

import java.io.IOException;
import java.io.InputStream;
import java.net.HttpURLConnection;
import java.net.URL;

/**
 * Created by glenn_000 on 28-Apr-15.
 */
public class RetrieveImageTask extends AsyncTask<String, Void, Bitmap> {

    ImageView image;
    public RetrieveImageTask(ImageView v) {
        image = v;
    }

    @Override
    protected void onPostExecute(Bitmap bmp) {
        image.setImageBitmap(bmp);
    }

    @Override
    protected Bitmap doInBackground(String... urls) {

        String imageUrl = urls[0];
        Bitmap image = null;

        try {

            URL url = new URL(imageUrl);
            HttpURLConnection urlConnection = (HttpURLConnection)url.openConnection();
            InputStream in = urlConnection.getInputStream();
            image = BitmapFactory.decodeStream(in);

        } catch (IOException e) {
            e.printStackTrace();
        }

        return image;
    }
}