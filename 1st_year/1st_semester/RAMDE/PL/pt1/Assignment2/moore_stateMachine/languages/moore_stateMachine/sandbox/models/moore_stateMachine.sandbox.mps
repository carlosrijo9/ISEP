<?xml version="1.0" encoding="UTF-8"?>
<model ref="r:44f3ff22-045d-47b9-b79b-b82eeab39608(moore_stateMachine.sandbox)">
  <persistence version="9" />
  <languages>
    <use id="37c2cb43-4835-4f1d-b147-4442de330b2c" name="moore_stateMachine" version="0" />
    <use id="f3061a53-9226-4cc5-a443-f952ceaf5816" name="jetbrains.mps.baseLanguage" version="11" />
  </languages>
  <imports />
  <registry>
    <language id="37c2cb43-4835-4f1d-b147-4442de330b2c" name="moore_stateMachine">
      <concept id="2729072192175766777" name="moore_stateMachine.structure.Action" flags="ng" index="KPY1a" />
      <concept id="2729072192175710025" name="moore_stateMachine.structure.Event" flags="ng" index="KQ0fU" />
      <concept id="2729072192175710031" name="moore_stateMachine.structure.Transition" flags="ng" index="KQ0fW">
        <reference id="2729072192175761522" name="target" index="KPZj1" />
        <reference id="2729072192175761518" name="event" index="KPZjt" />
      </concept>
      <concept id="2729072192175710028" name="moore_stateMachine.structure.State" flags="ng" index="KQ0fZ">
        <reference id="6350130079424483792" name="action" index="3PJE1T" />
        <child id="2729072192175761527" name="transition" index="KPZj4" />
      </concept>
      <concept id="2729072192175631056" name="moore_stateMachine.structure.StateMachine" flags="ng" index="KQvpz">
        <reference id="2729072192175760388" name="initialState" index="KPZyR" />
        <child id="2729072192175759266" name="state" index="KPWch" />
        <child id="2729072192175759264" name="event" index="KPWcj" />
        <child id="6350130079424486974" name="action" index="3PJEYn" />
      </concept>
    </language>
    <language id="ceab5195-25ea-4f22-9b92-103b95ca8c0c" name="jetbrains.mps.lang.core">
      <concept id="1169194658468" name="jetbrains.mps.lang.core.structure.INamedConcept" flags="ng" index="TrEIO">
        <property id="1169194664001" name="name" index="TrG5h" />
      </concept>
    </language>
  </registry>
  <node concept="KQvpz" id="2nvBbcl25Iu">
    <property role="TrG5h" value="LighSwitch" />
    <ref role="KPZyR" node="2nvBbcl26fD" resolve="lightOFF" />
    <node concept="KQ0fZ" id="2nvBbcl26fD" role="KPWch">
      <property role="TrG5h" value="lightOFF" />
      <ref role="3PJE1T" node="5wwcqAHBE5r" resolve="brightnessOFF" />
      <node concept="KQ0fW" id="2nvBbcl274T" role="KPZj4">
        <property role="TrG5h" value="off-to-dim" />
        <ref role="KPZjt" node="2nvBbcl26f$" resolve="onPressed" />
        <ref role="KPZj1" node="2nvBbcl26fF" resolve="lightONdim" />
      </node>
    </node>
    <node concept="KQ0fZ" id="2nvBbcl26fF" role="KPWch">
      <property role="TrG5h" value="lightONdim" />
      <ref role="3PJE1T" node="5wwcqAHBE5t" resolve="brightnessDim" />
      <node concept="KQ0fW" id="2nvBbcl274V" role="KPZj4">
        <property role="TrG5h" value="dim-to-medium" />
        <ref role="KPZjt" node="2nvBbcl26f$" resolve="onPressed" />
        <ref role="KPZj1" node="2nvBbcl26fI" resolve="lightONmedium" />
      </node>
      <node concept="KQ0fW" id="2nvBbcl274X" role="KPZj4">
        <property role="TrG5h" value="dim-to-off" />
        <ref role="KPZjt" node="2nvBbcl26fA" resolve="offPressed" />
        <ref role="KPZj1" node="2nvBbcl26fD" resolve="lightOFF" />
      </node>
    </node>
    <node concept="KQ0fZ" id="2nvBbcl26fI" role="KPWch">
      <property role="TrG5h" value="lightONmedium" />
      <ref role="3PJE1T" node="5wwcqAHBE5w" resolve="brightnessMedium" />
      <node concept="KQ0fW" id="2nvBbcl2750" role="KPZj4">
        <property role="TrG5h" value="medium-to-bright" />
        <ref role="KPZjt" node="2nvBbcl26f$" resolve="onPressed" />
        <ref role="KPZj1" node="2nvBbcl26fM" resolve="lightONbright" />
      </node>
      <node concept="KQ0fW" id="2nvBbcl2752" role="KPZj4">
        <property role="TrG5h" value="medium-to-off" />
        <ref role="KPZjt" node="2nvBbcl26fA" resolve="offPressed" />
        <ref role="KPZj1" node="2nvBbcl26fD" resolve="lightOFF" />
      </node>
    </node>
    <node concept="KQ0fZ" id="2nvBbcl26fM" role="KPWch">
      <property role="TrG5h" value="lightONbright" />
      <ref role="3PJE1T" node="5wwcqAHBE5$" resolve="brightnessHigh" />
      <node concept="KQ0fW" id="2nvBbcl2755" role="KPZj4">
        <property role="TrG5h" value="bright-to-dim" />
        <ref role="KPZjt" node="2nvBbcl26f$" resolve="onPressed" />
        <ref role="KPZj1" node="2nvBbcl26fF" resolve="lightONdim" />
      </node>
      <node concept="KQ0fW" id="2nvBbcl2757" role="KPZj4">
        <property role="TrG5h" value="bright-to-off" />
        <ref role="KPZjt" node="2nvBbcl26fA" resolve="offPressed" />
        <ref role="KPZj1" node="2nvBbcl26fD" resolve="lightOFF" />
      </node>
    </node>
    <node concept="KQ0fU" id="2nvBbcl26f$" role="KPWcj">
      <property role="TrG5h" value="onPressed" />
    </node>
    <node concept="KQ0fU" id="2nvBbcl26fA" role="KPWcj">
      <property role="TrG5h" value="offPressed" />
    </node>
    <node concept="KPY1a" id="5wwcqAHBE5r" role="3PJEYn">
      <property role="TrG5h" value="brightnessOFF" />
    </node>
    <node concept="KPY1a" id="5wwcqAHBE5t" role="3PJEYn">
      <property role="TrG5h" value="brightnessDim" />
    </node>
    <node concept="KPY1a" id="5wwcqAHBE5w" role="3PJEYn">
      <property role="TrG5h" value="brightnessMedium" />
    </node>
    <node concept="KPY1a" id="5wwcqAHBE5$" role="3PJEYn">
      <property role="TrG5h" value="brightnessHigh" />
    </node>
  </node>
</model>

