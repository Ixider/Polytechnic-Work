package glennsp1.bit.glennsp1prac7_2;

import android.app.Activity;
import android.os.Bundle;
import android.support.annotation.Nullable;
import android.support.v4.app.Fragment;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ListView;

import java.util.ArrayList;

/**
 * Created by glenn_000 on 27-Apr-15.
 */
public class TopArtistsFragment extends Fragment implements RetrieveTopArtistsTask.OnTaskResultListener {

    @Override
    public View onCreateView(LayoutInflater inflater, @Nullable ViewGroup container, @Nullable Bundle savedInstanceState) {
        View v = inflater.inflate(R.layout.fragment_top_artists, container, false);

        new RetrieveTopArtistsTask(this);
        return v;
    }

    @Override
    public void onResult(ArrayList<ArtistData> artists) {
        ((ListView)getActivity().findViewById(R.id.topArtistDisplay)).setAdapter(new ArtistArrayAdapter(getActivity(),R.layout.custom_list_view, artists));
    }

}
