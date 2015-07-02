package glennsp1.bit.thirdrdpartylibraries.RippleBackground;

import android.animation.Animator;
import android.animation.AnimatorSet;
import android.animation.ObjectAnimator;
import android.content.Context;
import android.content.res.TypedArray;
import android.graphics.Canvas;
import android.graphics.Paint;
import android.graphics.PointF;
import android.util.AttributeSet;
import android.view.View;
import android.view.animation.AccelerateDecelerateInterpolator;
import android.widget.RelativeLayout;
import java.util.ArrayList;
import glennsp1.bit.thirdrdpartylibraries.R;

/**
 * Created by fyu on 11/3/14.
 *
 * Modified by S.Glenn on 06/5/15
 */

public class RippleBackgroundView extends RelativeLayout {

    private static final int DEFAULT_RIPPLE_COUNT = 6;
    private static final int DEFAULT_DURATION_TIME = 100;
    private static final float DEFAULT_SCALE = 6.0f;
    private static final int DEFAULT_FILL_TYPE = 0;

    private int rippleColor;
    private float rippleStrokeWidth;
    private float rippleRadius;
    private int rippleDurationTime;
    private int rippleAmount;
    private int rippleDelay;
    private float rippleScale;
    private int rippleType;
    private Paint paint;
    private boolean animationRunning=false;
    private AnimatorSet animatorSet;
    private ArrayList<Animator> animatorList;
    private LayoutParams rippleParams;
    private ArrayList<RippleView> rippleViewList = new ArrayList<RippleView>();
    private PointF defaultLocation = new PointF(0, 0);

    public RippleBackgroundView(Context context) {
        super(context);
    }

    public RippleBackgroundView(Context context, AttributeSet attrs) {
        super(context, attrs);
        init(context, attrs);
    }

    public RippleBackgroundView(Context context, AttributeSet attrs, int defStyleAttr) {
        super(context, attrs, defStyleAttr);
        init(context, attrs);
    }

    private void init(final Context context, final AttributeSet attrs) {
        if (isInEditMode())
            return;

        if (null == attrs) {
            throw new IllegalArgumentException("Attributes should be provided to this view,");
        }

        final TypedArray typedArray = context.obtainStyledAttributes(attrs, R.styleable.RippleBackgroundView);
        rippleColor         =     typedArray.getColor(R.styleable.RippleBackgroundView_rb_color, getResources().getColor(R.color.rippelColor));
        rippleStrokeWidth   =     typedArray.getDimension(R.styleable.RippleBackgroundView_rb_strokeWidth, getResources().getDimension(R.dimen.rippleStrokeWidth));
        rippleRadius        =     typedArray.getDimension(R.styleable.RippleBackgroundView_rb_radius, getResources().getDimension(R.dimen.rippleRadius));
        rippleDurationTime  =     typedArray.getInt(R.styleable.RippleBackgroundView_rb_duration,DEFAULT_DURATION_TIME);
        rippleAmount        =     typedArray.getInt(R.styleable.RippleBackgroundView_rb_rippleAmount,DEFAULT_RIPPLE_COUNT);
        rippleScale         =     typedArray.getFloat(R.styleable.RippleBackgroundView_rb_scale,DEFAULT_SCALE);
        rippleType          =     typedArray.getInt(R.styleable.RippleBackgroundView_rb_type,DEFAULT_FILL_TYPE);
        typedArray.recycle();

        rippleDelay = rippleDurationTime / rippleAmount;

        paint = generatePaintObject();

        setLayoutParams(defaultLocation);
        setColor(rippleColor);

        setAnimatorList();

    }//End init

    private Paint generatePaintObject() {

        Paint paint = new Paint();
        paint.setAntiAlias(true);
        if (rippleType == DEFAULT_FILL_TYPE) {
            rippleStrokeWidth = 0;
            paint.setStyle(Paint.Style.FILL);
        } else {
            paint.setStyle(Paint.Style.STROKE);
        }

        return paint;
    }//End generatePaintObject

    private void setAnimatorList(){

        animatorSet = new AnimatorSet();
        animatorSet.setInterpolator(new AccelerateDecelerateInterpolator());

        animatorList = new ArrayList<Animator>();
        rippleViewList = new ArrayList<RippleView>();

        for(int i = 0; i < rippleAmount; i++) {
            RippleView rippleView = new RippleView(getContext());

            addView(rippleView,rippleParams);
            rippleViewList.add(rippleView);

            final ObjectAnimator scaleXAnimator = generateScaleXAnimator(i, rippleView);
            animatorList.add(scaleXAnimator);

            final ObjectAnimator scaleYAnimator = generateScaleYAnimator(i, rippleView);
            animatorList.add(scaleYAnimator);

            final ObjectAnimator alphaAnimator = generateAlphaAnimator(i, rippleView);
            animatorList.add(alphaAnimator);
        }

        animatorSet.playTogether(animatorList);
    }//End setAnimatorList

    //PRE:
    private ObjectAnimator generateScaleXAnimator(int rippleIndex, RippleView v) {

        final ObjectAnimator scaleXAnimator = ObjectAnimator.ofFloat(v, "ScaleX", 1.0f, rippleScale);

        scaleXAnimator.setRepeatCount(ObjectAnimator.INFINITE);
        scaleXAnimator.setRepeatMode(ObjectAnimator.RESTART);
        scaleXAnimator.setStartDelay(rippleIndex * rippleDelay);
        scaleXAnimator.setDuration(rippleDurationTime);

        return scaleXAnimator;
    }//End ObjectAnimator
    //POST:

    private ObjectAnimator generateScaleYAnimator(int rippleIndex, RippleView v) {

        final ObjectAnimator scaleYAnimator = ObjectAnimator.ofFloat(v, "ScaleY", 1.0f, rippleScale);

        scaleYAnimator.setRepeatCount(ObjectAnimator.INFINITE);
        scaleYAnimator.setRepeatMode(ObjectAnimator.RESTART);
        scaleYAnimator.setStartDelay(rippleIndex * rippleDelay);
        scaleYAnimator.setDuration(rippleDurationTime);

        return scaleYAnimator;
    }//End generateScaleYAnimator

    private ObjectAnimator generateAlphaAnimator(int rippleIndex, RippleView v) {

        final ObjectAnimator alphaAnimator = ObjectAnimator.ofFloat(v, "Alpha", 1.0f, 0f);

        alphaAnimator.setRepeatCount(ObjectAnimator.INFINITE);
        alphaAnimator.setRepeatMode(ObjectAnimator.RESTART);
        alphaAnimator.setStartDelay(rippleIndex * rippleDelay);
        alphaAnimator.setDuration(rippleDurationTime);

        return alphaAnimator;
    }//End generateAlphaAnimator


    private class RippleView extends View {

        public RippleView(Context context) {
            super(context);
            this.setVisibility(View.INVISIBLE);
        }//End RippleView Constructor

        @Override
        protected void onDraw(Canvas canvas) {
            float radius=(Math.min(getWidth(),getHeight()))/2;
            canvas.drawCircle(radius, radius, radius-rippleStrokeWidth, paint);
        }//End onDraw

    }//End RippleView

    public void startRippleAnimation(){
        if(!isRippleAnimationRunning()){
            for(RippleView rippleView:rippleViewList){
                rippleView.setVisibility(VISIBLE);
            }
            animatorSet.start();
            animationRunning = true;
        }
    }//End startRippleAnimation

    public void stopRippleAnimation(){
        if(isRippleAnimationRunning()){
            animatorSet.end();
            animationRunning=false;
        }
    }//End stopRippleAnimation

    public boolean isRippleAnimationRunning(){
        return animationRunning;
    }//End isRippleAnimationRunning

    public static class RippleParams {

        PointF Location;
        int Color;

        RippleParams(PointF location, int color) {
            Location = location;
            Color = color;
        }

    }//End RippleParams

    public void ConfigureRipple(RippleParams params) {
        if(params.Color != 0) {
            setColor(params.Color);
        } else {
            setColor(getResources().getColor(android.R.color.holo_blue_dark));
        }

        setLayoutParams(params.Location);
    }//End ConfigureRipple

    private void setColor(int color) {
        paint.setColor(color);
    }//End setColor

    private void setLayoutParams(PointF location) {
        rippleParams = new LayoutParams((int)(2*(rippleRadius+rippleStrokeWidth)),(int)(2*(rippleRadius+rippleStrokeWidth)));
        rippleParams.leftMargin = (int)location.x - (int)(rippleRadius + rippleStrokeWidth);
        rippleParams.topMargin  = (int)location.y - (int)(rippleRadius + rippleStrokeWidth);

        setAnimatorList();
    }//End setLayoutParams
}
