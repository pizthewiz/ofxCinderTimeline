# ofxCinderTimeline
`ofxCinderTimeline` is [Cinder](http://libcinder.org/)'s `Timeline` animation engine packaged as an [openFrameworks](http://www.openframeworks.cc/) addon. The `Timeline` API allows for the sophisticated animation of arbitrary properties. It supports a large library of easing functions as well as custom easing, callbacks and fire-and-forget tween management. The add source is taken directly from [Cinder 0.8.4](http://libcinder.org/blog/posts/6_cinder-084-released/) and unmodified (newer versions require not-yet-supported-by-openFrameworks [`C++11`](https://github.com/openframeworks/openFrameworks/issues/2577) and [`libc++`](https://github.com/openframeworks/openFrameworks/issues/1864)). `Timeline` is based on the [sc-Choreograph](https://github.com/sansumbrella/sc-Choreograph) CinderBlock by [David Wicks](http://sansumbrella.com/).

## EXAMPLES
_Basics_ - Take `pos` to (0,0) in 1 second using a quadratic easing curve. Immediately after that has completed, take `radius` to 3.0 in 5 seconds using the default linear easing.
```C++
ofxCinderTimeline::Anim<ofVec2f> pos;
ofxCinderTimeline::Anim<float> radius;
radius = 0.0f;
timeline().apply(&pos, ofVec2f::zero(), 1.0f, ofxCinderTimeline::EaseInQuad());
timeline().apply(&radius, 3.0f, 5.0f).appendTo(&pos);
```

_Callbacks_ - After a 4 second delay, animate `alpha` to 0.0 in 2 seconds using the default linear easing. When complete, the callback method `fadeOutFinished` will be run.
```C++
ofxCinderTimeline::Anim<float> alpha;
alpha = 1.0f;
timeline().appendTo(&alpha, 0.0f, 2.0f).delay(4.0f).finishFn(boost::bind(&ofApp::fadeOutFinished, this));
```

_Cues_ - In 5 seconds from now, run the callback method `cueHit`.
```C++
timeline().add(boost::bind(&ofApp::cueHit, this), timeline().getCurrentTime() + 5);
```

For more information, see the included example [_example-BasicTween_](example-BasicTween/), the [RFC: Timeline (+ Boost 1.48)](http://forum.libcinder.org/topic/rfc-timeline-boost-1-48) forum thread and the [`Timeline` documentation](http://libcinder.org/docs/v0.8.4/classcinder_1_1_timeline.html) from the Cinder library.

## NOTES
`Timeline` requires [Boost](http://boost.org) to compile. Download the [1.48 sources](http://sourceforge.net/projects/boost/files/boost/1.48.0/) unarchive and move the resulting *boost_1_48_0/boost* into _ofxCinderTimeline/libs_. The `ofxCinderTimeline` addon requires that _ofxCinderTimeline/libs_ and _ofxCinderTimeline/libs/cinder/include_ are included in the header search path.

#### ALERT
While Boost is required, you may **not** want to add it to your project as there are _8,654 header files_ - it only needs to be within the header search path! Both the [projectGenerator](https://github.com/ofZach/projectGeneratorSimple) and [OFPlugin](https://github.com/admsyn/OFPlugin) blow up trying to use `ofxCinderTimeline`, possibly due to the number of Boost headers. Until that is resolved, you may wish to add `ofxCinderTimeline` to your project manually.
