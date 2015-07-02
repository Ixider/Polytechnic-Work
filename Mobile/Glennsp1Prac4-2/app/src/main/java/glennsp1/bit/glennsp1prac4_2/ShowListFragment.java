package glennsp1.bit.glennsp1prac4_2;

import android.app.Activity;
import android.app.Fragment;
import android.os.Bundle;
import android.support.annotation.Nullable;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.AdapterView;
import android.widget.ArrayAdapter;
import android.widget.ListView;

/**
 * Created by glenn_000 on 29-Apr-15.
 */
public class ShowListFragment extends Fragment {

    OnItemSelectedListener onItemSelectedListener;
    public interface OnItemSelectedListener { public void onItemSelected(int pos); }
    @Nullable
    @Override
    public View onCreateView(LayoutInflater inflater, ViewGroup container, Bundle savedInstanceState) {
        View v = inflater.inflate(R.layout.show_an_list_fragment, container, false);

        String[] strings = getResources().getStringArray(R.array.placeholders);
        ArrayAdapter adapter = new ArrayAdapter(getActivity(), android.R.layout.simple_list_item_1, strings);

        ((ListView)v.findViewById(R.id.listView)).setAdapter(adapter);
        ((ListView)v.findViewById(R.id.listView)).setOnItemClickListener(onItemClickListener);

        return v;
    }

    @Override
    public void onAttach(Activity activity) {
        try {
            onItemSelectedListener = (OnItemSelectedListener)activity;
        } catch (ClassCastException e) {
            throw new ClassCastException("Class must implement OnTaskListener");
        }

        super.onAttach(activity);
    }

    @Override
    public void onDetach() {
        super.onDetach();
        onItemClickListener = null;
    }

    AdapterView.OnItemClickListener onItemClickListener = new AdapterView.OnItemClickListener() {
        @Override
            public void onItemClick(AdapterView<?> adapterView, View view, int i, long l) {
                onItemSelectedListener.onItemSelected(i);
        }
    };
}
