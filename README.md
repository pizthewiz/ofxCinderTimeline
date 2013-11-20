# ofxCinderTimeline
`ofxCinderTimeline` is [Cinder](http://libcinder.org/)'s `Timeline` animation engine packaged as an [openFrameworks](http://www.openframeworks.cc/) addon. The `Timeline` API allows for the sophisticated animation of arbitrary properties. It supports a large library of easing functions as well as custom easing, callbacks and fire-and-forget tween management. The add source is taken directly from [Cinder 0.8.4](http://libcinder.org/blog/posts/6_cinder-084-released/) and unmodified. `Timeline` is based on the [sc-Choreograph](https://github.com/sansumbrella/sc-Choreograph) CinderBlock by [David Wicks](http://sansumbrella.com/).

## Examples

Animate pos from its current value to (0,0) in 1sec using EaseInQuad. Immediately after that is complete, take pos to (10,20) in 2sec using the default linear easing.

```C++
ofxCinderTimeline::Anim<ofVec2f> pos;
timeline().apply( &pos, ofVec2f::zero(), 1.0f, ofxCinderTimeline::EaseInQuad() );
timeline().appendTo( &pos, ofVec2f( 10, 20 ), 2.0f );
```

Replace any existing tweens on pos and take it to (0,0) in 1sec using the default linear easing. Immediately after that is complete, replace all tweens on radius and take radius to 3 in 1sec also using the default linear easing.
```C++
ofxCinderTimeline::Anim<ofVec2f> pos;
ofxCinderTimeline::Anim<float> radius;
radius = 0.0f;
timeline().apply( &pos, ofVec2f::zero(), 1.0f );
timeline().apply( &radius, 3.0f, 1.0f ).appendTo( &pos );
```

See the included source example _example-BasicTween_, the [RFC: Timeline (+ Boost 1.48)](http://forum.libcinder.org/topic/rfc-timeline-boost-1-48) forum thread and the [documentation](http://libcinder.org/docs/v0.8.4/classcinder_1_1_timeline.html) from the Cinder library for more detail.

## Notes
The `ofxCinderTimeline` addon requires that `ofxCinderTimeline/libs/boost` and `ofxCinderTimeline/libs/cinder/include` are included in the header search path.
