package glennsp1.bit.glennsp1prac7_2;

import android.content.Context;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ArrayAdapter;
import android.widget.ImageView;
import android.widget.TextView;

import java.util.ArrayList;

/**
 * Created by glenn_000 on 28-Apr-15.
 */
public class ArtistArrayAdapter extends ArrayAdapter<ArtistData>
{

    public ArtistArrayAdapter(Context context, int resource, ArrayList<ArtistData> objects)
    {
        super(context, resource, objects);
    }

    @Override
    public View getView(int position, View convertView, ViewGroup container)
    {
        LayoutInflater layoutInflater = LayoutInflater.from(getContext());
        View v = layoutInflater.inflate(R.layout.custom_list_view, container, false);

        ArtistData currentArtist = this.getItem(position);
        new RetrieveImageTask((ImageView)v.findViewById(R.id.artistImage)).execute(currentArtist.ImageUrl);

        TextView artistName = (TextView)v.findViewById(R.id.artistDisplay);
        TextView artistUrl = (TextView)v.findViewById(R.id.artistUrlDisplay);

        artistName.setText(currentArtist.Name);
        artistUrl.setText(currentArtist.Url);

        return v;
    }
}// end class ToDoArrayAdapter
