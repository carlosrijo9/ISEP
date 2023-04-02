<?xml version="1.0" encoding="UTF-8"?>
<model ref="r:2d2fb68d-8243-4015-9fb8-d8469fa76ed9(mealyFSM.sandbox)">
  <persistence version="9" />
  <languages>
    <use id="dc97585e-752a-461c-8b39-6a0782f6bf23" name="mealyFSM" version="0" />
  </languages>
  <imports />
  <registry>
    <language id="dc97585e-752a-461c-8b39-6a0782f6bf23" name="mealyFSM">
      <concept id="3823129464717037744" name="mealyFSM.structure.action" flags="ng" index="ZLUHe" />
      <concept id="3823129464717037745" name="mealyFSM.structure.StateMachine" flags="ng" index="ZLUHf">
        <reference id="5314642073758562402" name="intialState" index="2ru1UG" />
        <child id="3823129464717038360" name="state" index="ZLUzA" />
        <child id="3823129464717038353" name="action" index="ZLUzJ" />
        <child id="3823129464717038351" name="event" index="ZLUzL" />
      </concept>
      <concept id="3823129464717037742" name="mealyFSM.structure.transition" flags="ng" index="ZLUHg">
        <reference id="5314642073758563676" name="action" index="2ru1Ii" />
        <reference id="5314642073758562410" name="target" index="2ru1U$" />
        <reference id="5314642073758562407" name="event" index="2ru1UD" />
      </concept>
      <concept id="3823129464717037743" name="mealyFSM.structure.event" flags="ng" index="ZLUHh" />
      <concept id="3823129464717037741" name="mealyFSM.structure.state" flags="ng" index="ZLUHj">
        <child id="5314642073758559306" name="transition" index="2ru0E4" />
      </concept>
    </language>
    <language id="ceab5195-25ea-4f22-9b92-103b95ca8c0c" name="jetbrains.mps.lang.core">
      <concept id="1169194658468" name="jetbrains.mps.lang.core.structure.INamedConcept" flags="ng" index="TrEIO">
        <property id="1169194664001" name="name" index="TrG5h" />
      </concept>
    </language>
  </registry>
  <node concept="ZLUHf" id="4B1pGViImL4">
    <property role="TrG5h" value="lightSwitch" />
    <ref role="2ru1UG" node="4B1pGViInxc" resolve="lightOff" />
    <node concept="ZLUHe" id="4B1pGViIo9$" role="ZLUzJ">
      <property role="TrG5h" value="brightnessOFF" />
    </node>
    <node concept="ZLUHe" id="4B1pGViIo9A" role="ZLUzJ">
      <property role="TrG5h" value="brightnessDim" />
    </node>
    <node concept="ZLUHe" id="4B1pGViIo9D" role="ZLUzJ">
      <property role="TrG5h" value="brightnessMedium" />
    </node>
    <node concept="ZLUHe" id="4B1pGViIo9H" role="ZLUzJ">
      <property role="TrG5h" value="brightnessHigh" />
    </node>
    <node concept="ZLUHj" id="4B1pGViInxc" role="ZLUzA">
      <property role="TrG5h" value="lightOff" />
      <node concept="ZLUHg" id="4B1pGViInPi" role="2ru0E4">
        <property role="TrG5h" value="off-to-dim" />
        <ref role="2ru1UD" node="4B1pGViImL5" resolve="onPressed" />
        <ref role="2ru1U$" node="4B1pGViIo8U" resolve="lightONdim" />
        <ref role="2ru1Ii" node="4B1pGViIo9A" resolve="brightnessDim" />
      </node>
    </node>
    <node concept="ZLUHj" id="4B1pGViIo8U" role="ZLUzA">
      <property role="TrG5h" value="lightONdim" />
      <node concept="ZLUHg" id="4B1pGViIo8Y" role="2ru0E4">
        <property role="TrG5h" value="dim-to-off" />
        <ref role="2ru1UD" node="4B1pGViImL7" resolve="offPressed" />
        <ref role="2ru1U$" node="4B1pGViInxc" resolve="lightOff" />
        <ref role="2ru1Ii" node="4B1pGViIo9$" resolve="brightnessOFF" />
      </node>
      <node concept="ZLUHg" id="4B1pGViIo90" role="2ru0E4">
        <property role="TrG5h" value="dim-ti-medium" />
        <ref role="2ru1UD" node="4B1pGViImL5" resolve="onPressed" />
        <ref role="2ru1U$" node="4B1pGViIo93" resolve="lightONmedium" />
        <ref role="2ru1Ii" node="4B1pGViIo9D" resolve="brightnessMedium" />
      </node>
    </node>
    <node concept="ZLUHj" id="4B1pGViIo93" role="ZLUzA">
      <property role="TrG5h" value="lightONmedium" />
      <node concept="ZLUHg" id="4B1pGViIo9a" role="2ru0E4">
        <property role="TrG5h" value="medium-to-off" />
        <ref role="2ru1UD" node="4B1pGViImL7" resolve="offPressed" />
        <ref role="2ru1U$" node="4B1pGViInxc" resolve="lightOff" />
        <ref role="2ru1Ii" node="4B1pGViIo9$" resolve="brightnessOFF" />
      </node>
      <node concept="ZLUHg" id="4B1pGViIo9c" role="2ru0E4">
        <property role="TrG5h" value="medium-to-bright" />
        <ref role="2ru1UD" node="4B1pGViImL5" resolve="onPressed" />
        <ref role="2ru1U$" node="4B1pGViIo9l" resolve="lightONbright" />
        <ref role="2ru1Ii" node="4B1pGViIo9H" resolve="brightnessHigh" />
      </node>
    </node>
    <node concept="ZLUHj" id="4B1pGViIo9l" role="ZLUzA">
      <property role="TrG5h" value="lightONbright" />
      <node concept="ZLUHg" id="4B1pGViIo9v" role="2ru0E4">
        <property role="TrG5h" value="bright-to-off" />
        <ref role="2ru1UD" node="4B1pGViImL7" resolve="offPressed" />
        <ref role="2ru1U$" node="4B1pGViInxc" resolve="lightOff" />
        <ref role="2ru1Ii" node="4B1pGViIo9$" resolve="brightnessOFF" />
      </node>
      <node concept="ZLUHg" id="4B1pGViIo9x" role="2ru0E4">
        <property role="TrG5h" value="bright-to-dim" />
        <ref role="2ru1UD" node="4B1pGViImL5" resolve="onPressed" />
        <ref role="2ru1U$" node="4B1pGViIo8U" resolve="lightONdim" />
        <ref role="2ru1Ii" node="4B1pGViIo9A" resolve="brightnessDim" />
      </node>
    </node>
    <node concept="ZLUHh" id="4B1pGViImL5" role="ZLUzL">
      <property role="TrG5h" value="onPressed" />
    </node>
    <node concept="ZLUHh" id="4B1pGViImL7" role="ZLUzL">
      <property role="TrG5h" value="offPressed" />
    </node>
  </node>
</model>

