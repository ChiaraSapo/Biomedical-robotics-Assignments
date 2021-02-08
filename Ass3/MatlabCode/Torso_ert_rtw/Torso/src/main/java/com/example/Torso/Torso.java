package com.example.Torso;

import android.Manifest;
import android.content.pm.PackageManager;
import android.os.Bundle;
import android.widget.Toast;
import android.util.Log;
import java.util.ArrayList;
import android.content.res.Configuration;
import androidx.core.app.ActivityCompat;
import androidx.fragment.app.Fragment;
import androidx.core.content.ContextCompat;
import com.google.android.material.tabs.TabLayout;
import androidx.viewpager.widget.ViewPager;
import androidx.appcompat.app.AppCompatActivity;
import androidx.appcompat.widget.Toolbar;
import android.content.Context;
import android.hardware.Sensor;
import android.hardware.SensorEvent;
import android.hardware.SensorEventListener;
import android.hardware.SensorManager;
import android.widget.FrameLayout;
import android.view.View;
import android.widget.ImageButton;
import android.os.CountDownTimer;
import android.os.Build;
import androidx.core.content.res.ResourcesCompat;

public class Torso extends AppCompatActivity implements SensorEventListener, OnFragmentInteractionListener {
    private SectionsPagerAdapter mSectionsPagerAdapter;

    private ViewPager mViewPager;
    private InfoFragment infoFragment = null;
    private ViewPager mCameraScopePager;

    private boolean isWidgetsLayoutHidden = false;
     private float[] mGyroscopeData = { 0.0f, 0.0f, 0.0f };
     private SensorManager mSensorManager;
    private static final int MY_PERMISSIONS_REQUEST_WRITE_STORAGE = 400;
    private boolean isWriteStoragePermissionGranted = false;
    private boolean isWriteStoragePermissionRequested = false;
    private String[] scopeTitles = {"Data (rad) 1", "Data (rad) 2", "Filtered Data (rad)  ", "Unfiltered Data (rad)  1"};

    private ImageButton btnZoom = null;
    private final CountDownTimer timerZoomButton = new CountDownTimer(5000, 1000) {
        @Override
        public void onTick(long l) {
            if (btnZoom!=null) {
                if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.HONEYCOMB) {
                    btnZoom.setAlpha(0.5f + 0.1f*l);
                }
            }
        }

        @Override
        public void onFinish() {
            if (btnZoom != null) {
                if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.HONEYCOMB) {
                    btnZoom.setAlpha(0.4f);
                }
            }
        }
    };
     private void registerSensorManager() {
        mSensorManager.registerListener(this,
            mSensorManager.getDefaultSensor(Sensor.TYPE_GYROSCOPE),
            SensorManager.SENSOR_DELAY_FASTEST);
     }

    private void registerAndSetChartSettingsOfaScope(int i) {
        FrameLayout frameLayout = (FrameLayout) findViewById(
                getResources().getIdentifier("scopeLayout" + i, "id", getPackageName()));
        if (null == frameLayout) {
            Log.e("MainActivity", "registerAndSetChartSettingsOfaScope: frameLayout is null.");
            return;
        }
        ScopeHelper.getInstance().putAChartInLayout(i, frameLayout, this);
    }

    private boolean checkIfAllPermissionsGranted()
    {
        return true && isWriteStoragePermissionGranted;
    }
    private void requestPermission() {
        String permissionRationale = "";
        // Here, thisClass is the current activity
        //request for external storage write
        if (ContextCompat.checkSelfPermission(thisClass,
                Manifest.permission.WRITE_EXTERNAL_STORAGE)
                != PackageManager.PERMISSION_GRANTED) {

            // Permission is not granted. Should we show an explanation?
            if (ActivityCompat.shouldShowRequestPermissionRationale(thisClass,
                    Manifest.permission.WRITE_EXTERNAL_STORAGE)) {
                permissionRationale += "Write external storage, ";
            } else {
                // No explanation needed; request the permission
                if (!isWriteStoragePermissionRequested) {
                    isWriteStoragePermissionRequested = true;
                    ActivityCompat.requestPermissions(thisClass,
                            new String[]{Manifest.permission.WRITE_EXTERNAL_STORAGE},
                            MY_PERMISSIONS_REQUEST_WRITE_STORAGE);
                    return;
                }
            }
        } else {
            // Permission has already been granted
            isWriteStoragePermissionGranted = true;
        }
        if (!permissionRationale.isEmpty())
            if (infoFragment != null) {
                infoFragment.updateModelInfo(permissionRationale + "permission not granted. Model cannot start.");
            }
    }
    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        Toolbar toolbar = (Toolbar) findViewById(R.id.toolbar);
        //Uncomment the following line to specify a custom App Title
        //toolbar.setTitle("My custom Title");
        setSupportActionBar(toolbar);

        // Create a FragmentPagerAdapter that returns individual fragments
        mSectionsPagerAdapter = new SectionsPagerAdapter(getSupportFragmentManager());

        // Set up the ViewPager with the sections adapter.
        mViewPager = (ViewPager) findViewById(R.id.container);
        mViewPager.setAdapter(mSectionsPagerAdapter);
        mViewPager.setOffscreenPageLimit(SectionsPagerAdapter.getNumTabs()-1);

        TabLayout tabLayout = (TabLayout) findViewById(R.id.tabs);
        tabLayout.setupWithViewPager(mViewPager);

        // Initiate the SensorManager
        mSensorManager = (SensorManager) getSystemService(Context.SENSOR_SERVICE);
        thisClass = this;
     }

    private Torso thisClass;
    private final Thread BgThread = new Thread() {
    @Override
    public void run() {
            String argv[] = new String[] {"MainActivity","Torso"};
            naMain(argv, thisClass);
        }
    };

    public void flashMessage(final String inMessage) {
        runOnUiThread(new Runnable() {
              public void run() {
                    Toast.makeText(getBaseContext(), inMessage, Toast.LENGTH_SHORT).show();
              }
        });
    }

    protected void onDestroy() {
         if (BgThread.isAlive())
             naOnAppStateChange(6);
         super.onDestroy();
         System.exit(0); //to kill all our threads.
    }

	@Override
    public void onAttachFragment(Fragment fragment) {
        super.onAttachFragment(fragment);
        if (fragment instanceof InfoFragment) {
            this.infoFragment = (InfoFragment) fragment;
            infoFragment.setFragmentInteractionListener(this);
            requestPermission();
        }
        if (fragment instanceof AppFragment) {
            ((AppFragment)fragment).setFragmentInteractionListener(this);
        }
        if (fragment instanceof CameraScopeFragment) {
            ((CameraScopeFragment)fragment).setFragmentInteractionListener(this);
        }
    }

	@Override
    public void onFragmentCreate(String name) {

    }

    @Override
    public void onFragmentStart(String name) {
        switch (name) {
            case "Info":
               break;
            case "App":
                if (mCameraScopePager == null) {
                    registerCameraScopeLayout();
                }
                break;
            case "dot1":
                registerAndSetChartSettingsOfaScope(1);
                break;
            case "dot2":
                registerAndSetChartSettingsOfaScope(2);
                break;
            case "dot3":
                registerAndSetChartSettingsOfaScope(3);
                break;
            case "dot4":
                registerAndSetChartSettingsOfaScope(4);
                break;
            default:
                break;
    }
    }

    @Override
    public void onFragmentResume(String name) {
        switch (name) {
            case "App":
                break;
            case "Info":
                if (checkIfAllPermissionsGranted()){
                    if (!BgThread.isAlive()) {
                        BgThread.start();
                    }
                }
                break;
            default:
                break;
        }
    }

    @Override
    public void onFragmentPause(String name) {
    }
    @Override
    protected void onResume() {
         super.onResume();
         if (BgThread.isAlive())
             naOnAppStateChange(3);
         registerSensorManager();
    }

    @Override
    protected void onPause() {
        if (BgThread.isAlive())
            naOnAppStateChange(4);
         mSensorManager.unregisterListener(this);
        super.onPause();
    }

    @Override
    public void onConfigurationChanged(Configuration newConfig) {
        super.onConfigurationChanged(newConfig);
    }

    @Override
    public void onRequestPermissionsResult(int requestCode,
                                           String permissions[], int[] grantResults) {
        switch (requestCode) {
            case MY_PERMISSIONS_REQUEST_WRITE_STORAGE:
                // If request is cancelled, the result arrays are empty.
                if (grantResults.length > 0
                        && grantResults[0] == PackageManager.PERMISSION_GRANTED) {
                    // permission was granted, yay! Do related task you need to do.
                    isWriteStoragePermissionGranted = true;
                } else {
                    // permission denied, boo!
                    flashMessage("Write external storage Permission not granted");
                }
                isWriteStoragePermissionRequested = false;
                break;

            // other case lines to check for other
            // permissions this app might request.
        }
        if (!checkIfAllPermissionsGranted()) {
            requestPermission();
        }
    }

    @Override
    public void onAccuracyChanged(Sensor sensor, int accuracy) {
    }

    @Override
    public void onSensorChanged(SensorEvent event) {
        float [] values = event.values;
        //Comment out if you want to log the data in logcat
        //String logMessage = String.format("%d: 0'%g'", event.sensor.getType(), values[0]);
        //Log.d("Sensor Data IN:", logMessage);
        switch(event.sensor.getType()) {
            case Sensor.TYPE_GYROSCOPE:
                mGyroscopeData[0] = values[0];
                mGyroscopeData[1] = values[1];
                mGyroscopeData[2] = values[2];
                break;
        }
    }

    // Get SensorEvent Data throws exception if the data is null
    public float[] getGyroscopeData() {
        return mGyroscopeData;
    }

    public void initScope(final int scopeID, final int numInputPorts, final byte[] attribute, final float[] sampleTimes) {
        ScopeHelper scopeHelper = ScopeHelper.getInstance();
        scopeHelper.initScope(scopeID, numInputPorts, attribute, sampleTimes);
        if (!scopeHelper.checkIfScopeRegistered(scopeID)){
            Log.w("MainActivity", "Scope not registered.");
            runOnUiThread(new Runnable() {
                @Override
                public void run() {
                    registerAndSetChartSettingsOfaScope(scopeID);
                }
            });
        }
        scopeHelper.setTitle(scopeID, scopeTitles[scopeID-1]);
    }

    public void cachePlotData(int scopeID, int portIdx, float[] data, int sigNumDims, int[] sigDims) {
        ScopeHelper.getInstance().cachePlotData(scopeID, portIdx, data, sigNumDims, sigDims);
    }

    public void plotData(int scopeID) {
        ScopeHelper.getInstance().plotData(scopeID);
    }
    private void registerCameraScopeLayout() {
        // Create the adapter that will return a fragment for each of the three
        // primary sections of the activity.
        CameraScopeSectionsPagerAdapter mCameraScopeAdapter = new CameraScopeSectionsPagerAdapter(getSupportFragmentManager());

        // Set up the ViewPager with the sections adapter.
        mCameraScopePager = (ViewPager) findViewById(R.id.cameraScopeContainer);
        mCameraScopePager.setOffscreenPageLimit(4);
        mCameraScopePager.setAdapter(mCameraScopeAdapter);

        TabLayout dotsLayout = (TabLayout) findViewById(R.id.dots);
        dotsLayout.setupWithViewPager(mCameraScopePager);

        ImageButton btnZoom = (ImageButton) findViewById(R.id.btnZoom);
        btnZoom.setVisibility(View.INVISIBLE);
    }
    private native int naMain(String[] argv, Torso pThis);
    private native void naOnAppStateChange(int state);
    static {
        System.loadLibrary("Torso");
    }

}
