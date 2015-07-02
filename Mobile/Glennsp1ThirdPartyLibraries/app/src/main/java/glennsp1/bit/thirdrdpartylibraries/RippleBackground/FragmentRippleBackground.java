package glennsp1.bit.thirdrdpartylibraries.RippleBackground;

import android.app.Fragment;
import android.graphics.Color;
import android.graphics.PointF;
import android.os.CountDownTimer;
import android.support.annotation.Nullable;
import android.os.Bundle;
import android.view.LayoutInflater;
import android.view.MotionEvent;
import android.view.View;
import android.view.ViewGroup;
import android.widget.RelativeLayout;
import android.widget.Toast;

import java.util.Random;

import glennsp1.bit.thirdrdpartylibraries.R;

public class FragmentRippleBackground extends Fragment {

    private static final long mAnimationLength = 5000;
    private static final long mAnimationTickLength = 1000;

    private RelativeLayout mContentContainer;

    @Nullable
    @Override
    public View onCreateView(LayoutInflater inflater, ViewGroup container, Bundle savedInstanceState) {
        View v = inflater.inflate(R.layout.fragment_ripple_background_layout, container, false);

        mContentContainer = (RelativeLayout)v.findViewById(R.id.contentContainer);
        mContentContainer.setOnTouchListener(onTouchListener);

        Toast.makeText(getActivity(), "Tap Screen to Spawn Ripples", Toast.LENGTH_LONG).show();

        return v;
    }//End onCreateView

    private RippleBackgroundView inflateRippleView(RippleBackgroundView.RippleParams params) {

        RelativeLayout contentContainer = (RelativeLayout)getActivity().findViewById(R.id.contentContainer);

        LayoutInflater inflater = getActivity().getLayoutInflater();

        RippleBackgroundView rippleBackgroundView =  (RippleBackgroundView)inflater.inflate(R.layout.view_ripple_background, contentContainer, false);

        rippleBackgroundView.ConfigureRipple(params);

        contentContainer.addView(rippleBackgroundView);

        return rippleBackgroundView;
    }//End inflateRippleView

    View.OnTouchListener onTouchListener = new View.OnTouchListener() {
        @Override
        public boolean onTouch(View view, MotionEvent motionEvent) {

            switch (motionEvent.getAction()) {
                case MotionEvent.ACTION_DOWN:

                    PointF location = new PointF(motionEvent.getX(), motionEvent.getY());

                    int rippleColor = generateRandomColor();
                    RippleBackgroundView.RippleParams params = new RippleBackgroundView.RippleParams(location, rippleColor);

                    RippleBackgroundView rippleBackgroundView = inflateRippleView(params);

                    runRippleAnimation(rippleBackgroundView);

                    break;
            }

            return false;
        }
    };//End onTouchListener

    private void removeViewFromContainer(View v) {
        mContentContainer.removeView(v);
    }//End removeViewFromContainer

    private void runRippleAnimation(final RippleBackgroundView rippleBackgroundView) {

        rippleBackgroundView.startRippleAnimation();
        rippleBackgroundView.animate().alpha(0f).setDuration(mAnimationLength);

        new CountDownTimer(mAnimationLength, mAnimationTickLength) {

            @Override
            public void onTick(long l) {}

            @Override
            public void onFinish() {
                rippleBackgroundView.stopRippleAnimation();
                removeViewFromContainer(rippleBackgroundView);
            }

        }.start();

    }//End runRippleAnimation

    private int generateRandomColor() {

        Random rnd = new Random();
        return Color.argb(255, rnd.nextInt(256), rnd.nextInt(256), rnd.nextInt(256));

    }//End generateRandomColor
}
