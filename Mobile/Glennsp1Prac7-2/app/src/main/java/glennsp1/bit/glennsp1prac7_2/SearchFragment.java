package glennsp1.bit.glennsp1prac7_2;

import android.content.Context;
import android.os.Bundle;
import android.support.annotation.Nullable;
import android.support.v4.app.Fragment;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ArrayAdapter;
import android.widget.ImageView;
import android.widget.ListView;
import android.widget.TextView;

import java.util.ArrayList;

/**
 * Created by glenn_000 on 27-Apr-15.
 */
public class SearchFragment extends Fragment implements RetrieveSearchTask.OnTaskResultListener {
    RetrieveSearchTask mDataFactory;

    @Override
    public View onCreateView(LayoutInflater inflater, @Nullable ViewGroup container, @Nullable Bundle savedInstanceState) {
        View v = inflater.inflate(R.layout.fragment_search, container, false);

        v.findViewById(R.id.commitSearch).setOnClickListener(onSearchClick);

        mDataFactory = new RetrieveSearchTask(this);

        return v;
    }

    private void setListAdapter(ArrayList<ArtistData> artistList) {
        ((ListView)getView().findViewById(R.id.searchList)).setAdapter(new ArtistArrayAdapter(getActivity(), R.layout.custom_list_view, artistList));
    }

    private String retrieveInputString() {
        return ((TextView)(this.getView().findViewById(R.id.searchInput))).getText().toString();
    }

    private void search(String input) {
        mDataFactory.Search(input);
    }

    View.OnClickListener onSearchClick = new View.OnClickListener() {
        @Override
        public void onClick(View view) {
            search(retrieveInputString());
        }
    };

    @Override
    public void onResult(ArrayList<ArtistData> artists) {
        setListAdapter(artists);
    }


}
