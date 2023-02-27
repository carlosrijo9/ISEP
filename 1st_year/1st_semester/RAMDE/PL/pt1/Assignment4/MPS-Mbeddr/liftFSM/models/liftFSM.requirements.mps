<?xml version="1.0" encoding="UTF-8"?>
<model ref="r:46c7fdec-dff5-4c1d-9d05-dbb54255fd69(liftFSM.requirements)">
  <persistence version="9" />
  <languages>
    <use id="564e97d6-8fb7-41f5-bfc1-c7ed376efd62" name="com.mbeddr.ext.statemachines" version="1" />
    <devkit ref="8a4402f1-8f1e-44d8-a4f6-f174fa7cf42e(com.mbeddr.cc.reqtrace.c)" />
    <devkit ref="d2a9c55c-6bdc-4cc2-97e1-4ba7552f5584(com.mbeddr.core)" />
    <devkit ref="24565007-e59f-42fc-ac10-da3836deec1c(com.mbeddr.components)" />
    <devkit ref="b31efd26-898e-4b0e-b5dc-2d7ced06e7f7(com.mbeddr.cc.variability)" />
    <devkit ref="a4dac888-0788-4852-b4c0-f386bf6f2c0b(com.mbeddr.cc.reqtrace)" />
    <devkit ref="54c79f9f-f3ba-4167-91f1-eb4e98a9c47c(com.mbeddr.documentation)" />
  </languages>
  <imports />
  <registry>
    <language id="d6714220-402d-48cb-a4a2-88223c6257f6" name="com.mbeddr.cc.requirements.scenarios">
      <concept id="6514529288613812198" name="com.mbeddr.cc.requirements.scenarios.structure.UseCaseKind" flags="ng" index="4R1oT" />
      <concept id="6514529288613812195" name="com.mbeddr.cc.requirements.scenarios.structure.UseCase" flags="ng" index="4R1oW">
        <child id="6514529288613824147" name="contents" index="4Rctc" />
      </concept>
      <concept id="6514529288613845835" name="com.mbeddr.cc.requirements.scenarios.structure.UseCasePassiveActor" flags="ng" index="4R9Ek">
        <child id="6514529288613845836" name="participant" index="4R9Ej" />
      </concept>
      <concept id="6514529288613824161" name="com.mbeddr.cc.requirements.scenarios.structure.UseCaseActiveActor" flags="ng" index="4RctY">
        <child id="6514529288613824163" name="participant" index="4RctW" />
      </concept>
      <concept id="3126418051240013621" name="com.mbeddr.cc.requirements.scenarios.structure.UseCaseSummary" flags="ng" index="oTeIi" />
      <concept id="5744000828452956484" name="com.mbeddr.cc.requirements.scenarios.structure.SelfCall" flags="ng" index="16Mycm" />
      <concept id="5744000828452822758" name="com.mbeddr.cc.requirements.scenarios.structure.ComponentRequirementKind" flags="ng" index="16N1iO" />
      <concept id="5744000828452824074" name="com.mbeddr.cc.requirements.scenarios.structure.ParticipantRef" flags="ng" index="16N2To">
        <reference id="5744000828452824075" name="participant" index="16N2Tp" />
      </concept>
      <concept id="5744000828452824073" name="com.mbeddr.cc.requirements.scenarios.structure.Scenario" flags="ng" index="16N2Tr">
        <child id="5744000828452824190" name="initials" index="16N2SG" />
      </concept>
      <concept id="5744000828452824121" name="com.mbeddr.cc.requirements.scenarios.structure.InitialContext" flags="ng" index="16N2TF">
        <reference id="5744000828452824122" name="initiator" index="16N2TC" />
      </concept>
      <concept id="5744000828452849517" name="com.mbeddr.cc.requirements.scenarios.structure.NonSelfCall" flags="ng" index="16NoOZ">
        <child id="5744000828452849518" name="targetParticipant" index="16NoOW" />
      </concept>
      <concept id="5744000828452862536" name="com.mbeddr.cc.requirements.scenarios.structure.ICallContext" flags="ng" index="16Nr0q">
        <child id="5744000828452862537" name="contents" index="16Nr0r" />
      </concept>
      <concept id="5744000828452835552" name="com.mbeddr.cc.requirements.scenarios.structure.ScenarioRequirementKind" flags="ng" index="16NtEM" />
      <concept id="5744000828452842290" name="com.mbeddr.cc.requirements.scenarios.structure.SequentialCall" flags="ng" index="16Nu5w" />
      <concept id="5744000828452842288" name="com.mbeddr.cc.requirements.scenarios.structure.Call" flags="ng" index="16Nu5y">
        <reference id="5744000828452854655" name="capability" index="16Np4H" />
      </concept>
      <concept id="5744000828452694711" name="com.mbeddr.cc.requirements.scenarios.structure.Collaboration" flags="ng" index="16Ny3_">
        <property id="5744000828452816602" name="description" index="16N0M8" />
        <reference id="5744000828452694713" name="participant" index="16Ny3F" />
      </concept>
      <concept id="5744000828452661378" name="com.mbeddr.cc.requirements.scenarios.structure.Actor" flags="ng" index="16NEbg" />
      <concept id="5744000828452661387" name="com.mbeddr.cc.requirements.scenarios.structure.Component" flags="ng" index="16NEbp" />
      <concept id="5744000828452661413" name="com.mbeddr.cc.requirements.scenarios.structure.Capability" flags="ng" index="16NEbR" />
      <concept id="5744000828452649492" name="com.mbeddr.cc.requirements.scenarios.structure.Participant" flags="ng" index="16NJ16">
        <child id="5744000828452661377" name="contents" index="16NEbj" />
      </concept>
    </language>
    <language id="92d2ea16-5a42-4fdf-a676-c7604efe3504" name="de.slisson.mps.richtext">
      <concept id="2557074442922380897" name="de.slisson.mps.richtext.structure.Text" flags="ng" index="19SGf9">
        <child id="2557074442922392302" name="words" index="19SJt6" />
      </concept>
      <concept id="2557074442922438156" name="de.slisson.mps.richtext.structure.Word" flags="ng" index="19SUe$">
        <property id="2557074442922438158" name="escapedValue" index="19SUeA" />
      </concept>
    </language>
    <language id="2374bc90-7e37-41f1-a9c4-c2e35194c36a" name="com.mbeddr.doc">
      <concept id="6657644269295214799" name="com.mbeddr.doc.structure.IDocumentLike" flags="ng" index="G9hjZ">
        <reference id="6657644269295214800" name="config" index="G9hjw" />
      </concept>
      <concept id="6386504476136472795" name="com.mbeddr.doc.structure.PathDefinition" flags="ng" index="2SbYGw">
        <child id="2642765975824057986" name="pathPicker" index="9PVG_" />
      </concept>
      <concept id="6386504476136472782" name="com.mbeddr.doc.structure.DocumentConfig" flags="ng" index="2SbYGP">
        <child id="6617418817009206267" name="defaultImagePath" index="A10yx" />
        <child id="5785245534401182264" name="defaultTempPath" index="Cbewh" />
      </concept>
      <concept id="3350625596580089586" name="com.mbeddr.doc.structure.TextParagraph" flags="ng" index="1_0LV8">
        <child id="3350625596580089613" name="text" index="1_0LWR" />
      </concept>
      <concept id="3350625596580064249" name="com.mbeddr.doc.structure.IDocContentContainer" flags="ng" index="1_0VJ3">
        <child id="3350625596580064250" name="contents" index="1_0VJ0" />
      </concept>
    </language>
    <language id="d4280a54-f6df-4383-aa41-d1b2bffa7eb1" name="com.mbeddr.core.base">
      <concept id="8375407818529178006" name="com.mbeddr.core.base.structure.TextBlock" flags="ng" index="OjmMv">
        <child id="8375407818529178007" name="text" index="OjmMu" />
      </concept>
      <concept id="747084250476811597" name="com.mbeddr.core.base.structure.DefaultGenericChunkDependency" flags="ng" index="3GEVxB">
        <reference id="747084250476878887" name="chunk" index="3GEb4d" />
      </concept>
    </language>
    <language id="d3a0fd26-445a-466c-900e-10444ddfed52" name="com.mbeddr.mpsutil.filepicker">
      <concept id="2642765975824060179" name="com.mbeddr.mpsutil.filepicker.structure.SolutionRelativeDirPicker" flags="ng" index="9PVaO" />
      <concept id="6156524541422549000" name="com.mbeddr.mpsutil.filepicker.structure.AbstractPicker" flags="ng" index="3N1QpV">
        <property id="6156524541422553710" name="path" index="3N1Lgt" />
      </concept>
    </language>
    <language id="e865cad2-7cc8-437a-951a-665bcbcb8b1a" name="com.mbeddr.cc.requirements">
      <concept id="8921256082857728250" name="com.mbeddr.cc.requirements.structure.FunctionalRequirementKind" flags="ng" index="22Mrfp" />
      <concept id="3814452005696780739" name="com.mbeddr.cc.requirements.structure.ReqRefWord" flags="ng" index="2oIDSw" />
      <concept id="3352153450712436945" name="com.mbeddr.cc.requirements.structure.AbstractReqRefWord" flags="ng" index="2wPqOs">
        <reference id="3352153450712436947" name="req" index="2wPqOu" />
      </concept>
      <concept id="6657644269295006436" name="com.mbeddr.cc.requirements.structure.ReqDocParagraph" flags="ng" index="GmGrk" />
      <concept id="8983772170066800838" name="com.mbeddr.cc.requirements.structure.DefaultRequirementsClass" flags="ng" index="2RsZnQ" />
      <concept id="8745401669462963169" name="com.mbeddr.cc.requirements.structure.RequirementsModule" flags="ng" index="3fbPIq">
        <child id="2588579461811806005" name="abstract" index="tLAhV" />
        <child id="8983772170066800844" name="cls" index="2RsZnW" />
        <child id="8745401669462963171" name="requirements" index="3fbPIo" />
        <child id="1165432222362099166" name="imports" index="1BwUYK" />
      </concept>
      <concept id="8745401669462952101" name="com.mbeddr.cc.requirements.structure.Requirement" flags="ng" index="3fbQ3u">
        <property id="3266388008823942437" name="createdAt" index="2DRQuN" />
        <property id="3266388008825423946" name="createdBy" index="2DXwbs" />
        <property id="3402431285977818823" name="summmary" index="1ylvJX" />
        <child id="8921256082857728256" name="kind" index="22Mr8z" />
        <child id="6657644269295007507" name="doc" index="GmGcz" />
        <child id="8745401669463270518" name="additionalData" index="3faCKd" />
        <child id="8745401669462962629" name="details" index="3fbPAY" />
      </concept>
    </language>
    <language id="ceab5195-25ea-4f22-9b92-103b95ca8c0c" name="jetbrains.mps.lang.core">
      <concept id="1169194658468" name="jetbrains.mps.lang.core.structure.INamedConcept" flags="ng" index="TrEIO">
        <property id="1169194664001" name="name" index="TrG5h" />
      </concept>
    </language>
  </registry>
  <node concept="3fbPIq" id="WfF1I4h9CW">
    <property role="TrG5h" value="Actuators" />
    <ref role="G9hjw" node="WfF1I4h9D1" resolve="DefaultDocConfig" />
    <node concept="OjmMv" id="WfF1I4h9CX" role="tLAhV">
      <node concept="19SGf9" id="WfF1I4h9CY" role="OjmMu">
        <node concept="19SUe$" id="WfF1I4h9CZ" role="19SJt6" />
      </node>
    </node>
    <node concept="2RsZnQ" id="WfF1I4h9D0" role="2RsZnW" />
    <node concept="3GEVxB" id="WfF1I4h9Gl" role="1BwUYK">
      <ref role="3GEb4d" node="WfF1I4h9Fc" resolve="Components" />
    </node>
    <node concept="3fbQ3u" id="WfF1I4h9RR" role="3fbPIo">
      <property role="2DRQuN" value="1669834916774" />
      <property role="2DXwbs" value="rijo" />
      <property role="1ylvJX" value="User" />
      <property role="TrG5h" value="User" />
      <node concept="GmGrk" id="WfF1I4h9RT" role="GmGcz">
        <node concept="1_0LV8" id="WfF1I4h9RU" role="1_0VJ0">
          <node concept="19SGf9" id="WfF1I4h9RV" role="1_0LWR">
            <node concept="19SUe$" id="WfF1I4h9RW" role="19SJt6" />
          </node>
        </node>
      </node>
      <node concept="16N1iO" id="WfF1I4h9RQ" role="22Mr8z" />
      <node concept="16NEbg" id="WfF1I4h9S5" role="3faCKd">
        <property role="TrG5h" value="User" />
        <node concept="16NEbR" id="WfF1I4h9S8" role="16NEbj">
          <property role="TrG5h" value="interact" />
        </node>
        <node concept="16NEbR" id="WfF1I4js9o" role="16NEbj">
          <property role="TrG5h" value="maxWeight" />
        </node>
        <node concept="16Ny3_" id="WfF1I4h9So" role="16NEbj">
          <property role="16N0M8" value="to call the lift to the floor" />
          <ref role="16Ny3F" node="WfF1I4h_98" resolve="callLift" />
        </node>
        <node concept="16Ny3_" id="WfF1I4ha1X" role="16NEbj">
          <property role="16N0M8" value="to select the destination (or target) floor" />
          <ref role="16Ny3F" node="WfF1I4h9X6" resolve="targetFloor" />
        </node>
        <node concept="16Ny3_" id="WfF1I4ha27" role="16NEbj">
          <property role="16N0M8" value="to activate the emergency system" />
          <ref role="16Ny3F" node="WfF1I4h9XC" resolve="emergencyButton" />
        </node>
        <node concept="16Ny3_" id="WfF1I4ha2j" role="16NEbj">
          <property role="16N0M8" value="to open the lift doors" />
          <ref role="16Ny3F" node="WfF1I4h9Zb" resolve="openDoor" />
        </node>
        <node concept="16Ny3_" id="WfF1I4ha2x" role="16NEbj">
          <property role="16N0M8" value="to close the lift doors" />
          <ref role="16Ny3F" node="WfF1I4ha19" resolve="closeDoor" />
        </node>
        <node concept="16Ny3_" id="WfF1I4jrJR" role="16NEbj">
          <ref role="16Ny3F" node="WfF1I4h9T1" resolve="liftControl" />
        </node>
      </node>
    </node>
    <node concept="3fbQ3u" id="WfF1I4h9V8" role="3fbPIo">
      <property role="2DRQuN" value="1669835300500" />
      <property role="2DXwbs" value="rijo" />
      <property role="1ylvJX" value="Safety Team" />
      <property role="TrG5h" value="safetyTeam" />
      <node concept="GmGrk" id="WfF1I4h9Va" role="GmGcz">
        <node concept="1_0LV8" id="WfF1I4h9Vb" role="1_0VJ0">
          <node concept="19SGf9" id="WfF1I4h9Vc" role="1_0LWR">
            <node concept="19SUe$" id="WfF1I4h9Vd" role="19SJt6" />
          </node>
        </node>
      </node>
      <node concept="16N1iO" id="WfF1I4h9Vu" role="22Mr8z" />
      <node concept="16NEbg" id="WfF1I4haJ_" role="3faCKd">
        <property role="TrG5h" value="safetyTeam" />
        <node concept="16NEbR" id="WfF1I4haKI" role="16NEbj">
          <property role="TrG5h" value="releaseEmergencyAlarm" />
        </node>
        <node concept="16NEbR" id="WfF1I4jIoF" role="16NEbj">
          <property role="TrG5h" value="releaseEmergencyButton" />
        </node>
        <node concept="16Ny3_" id="WfF1I4js0p" role="16NEbj">
          <ref role="16Ny3F" node="WfF1I4iXR0" resolve="emergencyAlarm" />
        </node>
        <node concept="16Ny3_" id="WfF1I4jIpE" role="16NEbj">
          <ref role="16Ny3F" node="WfF1I4h9XC" resolve="emergencyButton" />
        </node>
      </node>
    </node>
    <node concept="3fbQ3u" id="WfF1I4h_aI" role="3fbPIo">
      <property role="2DRQuN" value="1669904612024" />
      <property role="2DXwbs" value="rijo" />
      <property role="1ylvJX" value="Floor Display" />
      <property role="TrG5h" value="floorDisplay" />
      <node concept="GmGrk" id="WfF1I4h_aK" role="GmGcz">
        <node concept="1_0LV8" id="WfF1I4h_aL" role="1_0VJ0">
          <node concept="19SGf9" id="WfF1I4h_aM" role="1_0LWR">
            <node concept="19SUe$" id="WfF1I4h_aN" role="19SJt6" />
          </node>
        </node>
      </node>
      <node concept="16N1iO" id="WfF1I4h_bg" role="22Mr8z" />
      <node concept="16NEbg" id="WfF1I4h_ck" role="3faCKd">
        <property role="TrG5h" value="floorDisplay" />
        <node concept="16NEbR" id="WfF1I4h_cn" role="16NEbj">
          <property role="TrG5h" value="showLiftMovement" />
        </node>
        <node concept="16NEbR" id="WfF1I4h_cy" role="16NEbj">
          <property role="TrG5h" value="showLiftFloor" />
        </node>
      </node>
    </node>
  </node>
  <node concept="2SbYGP" id="WfF1I4h9D1">
    <property role="TrG5h" value="DefaultDocConfig" />
    <node concept="2SbYGw" id="WfF1I4h9D2" role="Cbewh">
      <property role="TrG5h" value="temp" />
      <node concept="9PVaO" id="WfF1I4h9D3" role="9PVG_">
        <property role="3N1Lgt" value="." />
      </node>
    </node>
    <node concept="2SbYGw" id="WfF1I4h9Qx" role="A10yx">
      <property role="TrG5h" value="img" />
      <node concept="9PVaO" id="WfF1I4h9Qy" role="9PVG_">
        <property role="3N1Lgt" value="." />
      </node>
    </node>
  </node>
  <node concept="3fbPIq" id="WfF1I4h9Fc">
    <property role="TrG5h" value="Components" />
    <ref role="G9hjw" node="WfF1I4h9D1" resolve="DefaultDocConfig" />
    <node concept="OjmMv" id="WfF1I4h9Fd" role="tLAhV">
      <node concept="19SGf9" id="WfF1I4h9Fe" role="OjmMu">
        <node concept="19SUe$" id="WfF1I4h9Ff" role="19SJt6" />
      </node>
    </node>
    <node concept="2RsZnQ" id="WfF1I4h9Fg" role="2RsZnW" />
    <node concept="3GEVxB" id="WfF1I4h9IG" role="1BwUYK">
      <ref role="3GEb4d" node="WfF1I4h9CW" resolve="Actuators" />
    </node>
    <node concept="3fbQ3u" id="WfF1I4h9SG" role="3fbPIo">
      <property role="2DRQuN" value="1669835104511" />
      <property role="2DXwbs" value="rijo" />
      <property role="1ylvJX" value="Lift Control" />
      <property role="TrG5h" value="liftControl" />
      <node concept="GmGrk" id="WfF1I4h9SI" role="GmGcz">
        <node concept="1_0LV8" id="WfF1I4h9SJ" role="1_0VJ0">
          <node concept="19SGf9" id="WfF1I4h9SK" role="1_0LWR">
            <node concept="19SUe$" id="WfF1I4h9SL" role="19SJt6" />
          </node>
        </node>
      </node>
      <node concept="16N1iO" id="WfF1I4h9SU" role="22Mr8z" />
      <node concept="16NEbp" id="WfF1I4h9T1" role="3faCKd">
        <property role="TrG5h" value="liftControl" />
        <node concept="16NEbR" id="WfF1I4jrLJ" role="16NEbj">
          <property role="TrG5h" value="receiveTargetFloor" />
        </node>
        <node concept="16NEbR" id="WfF1I4js0K" role="16NEbj">
          <property role="TrG5h" value="receiveEmergencyStatus" />
        </node>
        <node concept="16NEbR" id="WfF1I4js1y" role="16NEbj">
          <property role="TrG5h" value="receiveMaxWeightTrigger" />
        </node>
        <node concept="16NEbR" id="WfF1I4jsgp" role="16NEbj">
          <property role="TrG5h" value="receiveDetectionBarrierTrigger" />
        </node>
        <node concept="16NEbR" id="WfF1I4jufJ" role="16NEbj">
          <property role="TrG5h" value="receiveDoorEOLTrigger" />
        </node>
        <node concept="16NEbR" id="WfF1I4j_nS" role="16NEbj">
          <property role="TrG5h" value="timeoutRelease" />
        </node>
        <node concept="16NEbR" id="WfF1I4jBl4" role="16NEbj">
          <property role="TrG5h" value="timeoutOpenDoors" />
        </node>
        <node concept="16NEbR" id="WfF1I4h9T4" role="16NEbj">
          <property role="TrG5h" value="controlLift" />
        </node>
        <node concept="16Ny3_" id="WfF1I4jrL_" role="16NEbj">
          <ref role="16Ny3F" node="WfF1I4h_98" resolve="callLift" />
        </node>
        <node concept="16Ny3_" id="WfF1I4jrRS" role="16NEbj">
          <ref role="16Ny3F" node="WfF1I4iXR0" resolve="emergencyAlarm" />
        </node>
        <node concept="16Ny3_" id="WfF1I4jrS6" role="16NEbj">
          <ref role="16Ny3F" node="WfF1I4h9XC" resolve="emergencyButton" />
        </node>
        <node concept="16Ny3_" id="WfF1I4jrSm" role="16NEbj">
          <ref role="16Ny3F" node="WfF1I4h9X6" resolve="targetFloor" />
        </node>
        <node concept="16Ny3_" id="WfF1I4jrSC" role="16NEbj">
          <ref role="16Ny3F" node="WfF1I4h9Zb" resolve="openDoor" />
        </node>
        <node concept="16Ny3_" id="WfF1I4jrSW" role="16NEbj">
          <ref role="16Ny3F" node="WfF1I4ha19" resolve="closeDoor" />
        </node>
        <node concept="16Ny3_" id="WfF1I4jrTi" role="16NEbj">
          <ref role="16Ny3F" node="WfF1I4ha4m" resolve="doorEOL" />
        </node>
        <node concept="16Ny3_" id="WfF1I4jrTE" role="16NEbj">
          <ref role="16Ny3F" node="WfF1I4ha5l" resolve="detectionBarrier" />
        </node>
        <node concept="16Ny3_" id="WfF1I4jrU4" role="16NEbj">
          <ref role="16Ny3F" node="WfF1I4iXHN" resolve="weightAlarm" />
        </node>
        <node concept="16Ny3_" id="WfF1I4jrUw" role="16NEbj">
          <ref role="16Ny3F" node="WfF1I4ha6t" resolve="weightCell" />
        </node>
        <node concept="16Ny3_" id="WfF1I4jrUY" role="16NEbj">
          <ref role="16Ny3F" node="WfF1I4ha7I" resolve="floorSensor" />
        </node>
        <node concept="16Ny3_" id="WfF1I4jrVu" role="16NEbj">
          <ref role="16Ny3F" node="WfF1I4iw55" resolve="motorCloseDoors" />
        </node>
        <node concept="16Ny3_" id="WfF1I4jrW0" role="16NEbj">
          <ref role="16Ny3F" node="WfF1I4ivZC" resolve="motorDown" />
        </node>
        <node concept="16Ny3_" id="WfF1I4jrW$" role="16NEbj">
          <ref role="16Ny3F" node="WfF1I4iw4W" resolve="motorOpenDoors" />
        </node>
        <node concept="16Ny3_" id="WfF1I4jrXa" role="16NEbj">
          <ref role="16Ny3F" node="WfF1I4ivZ6" resolve="motorUp" />
        </node>
      </node>
    </node>
    <node concept="3fbQ3u" id="WfF1I4h_92" role="3fbPIo">
      <property role="2DRQuN" value="1669835104511" />
      <property role="2DXwbs" value="rijo" />
      <property role="1ylvJX" value="Call Lift Button" />
      <property role="TrG5h" value="callLift" />
      <node concept="GmGrk" id="WfF1I4h_93" role="GmGcz">
        <node concept="1_0LV8" id="WfF1I4h_94" role="1_0VJ0">
          <node concept="19SGf9" id="WfF1I4h_95" role="1_0LWR">
            <node concept="19SUe$" id="WfF1I4h_96" role="19SJt6" />
          </node>
        </node>
      </node>
      <node concept="16N1iO" id="WfF1I4h_97" role="22Mr8z" />
      <node concept="16NEbp" id="WfF1I4h_98" role="3faCKd">
        <property role="TrG5h" value="callLift" />
        <node concept="16NEbR" id="WfF1I4h_99" role="16NEbj">
          <property role="TrG5h" value="sendTargetFloor" />
        </node>
        <node concept="16Ny3_" id="WfF1I4h_9a" role="16NEbj">
          <ref role="16Ny3F" node="WfF1I4h9T1" resolve="liftControl" />
        </node>
      </node>
    </node>
    <node concept="3fbQ3u" id="WfF1I4h9Vz" role="3fbPIo">
      <property role="2DRQuN" value="1669835434796" />
      <property role="2DXwbs" value="rijo" />
      <property role="1ylvJX" value="Target Floor Button" />
      <property role="TrG5h" value="targetFloor" />
      <node concept="GmGrk" id="WfF1I4h9V_" role="GmGcz">
        <node concept="1_0LV8" id="WfF1I4h9VA" role="1_0VJ0">
          <node concept="19SGf9" id="WfF1I4h9VB" role="1_0LWR">
            <node concept="19SUe$" id="WfF1I4h9VC" role="19SJt6" />
          </node>
        </node>
      </node>
      <node concept="16N1iO" id="WfF1I4h9X1" role="22Mr8z" />
      <node concept="16NEbp" id="WfF1I4h9X6" role="3faCKd">
        <property role="TrG5h" value="targetFloor" />
        <node concept="16NEbR" id="WfF1I4h9X9" role="16NEbj">
          <property role="TrG5h" value="selectTargetFloor" />
        </node>
        <node concept="16Ny3_" id="WfF1I4h9Xu" role="16NEbj">
          <ref role="16Ny3F" node="WfF1I4h9T1" resolve="liftControl" />
        </node>
      </node>
    </node>
    <node concept="3fbQ3u" id="WfF1I4h9Xy" role="3fbPIo">
      <property role="2DRQuN" value="1669835434796" />
      <property role="2DXwbs" value="rijo" />
      <property role="1ylvJX" value="Emergency Button" />
      <property role="TrG5h" value="emergencyButton" />
      <node concept="GmGrk" id="WfF1I4h9Xz" role="GmGcz">
        <node concept="1_0LV8" id="WfF1I4h9X$" role="1_0VJ0">
          <node concept="19SGf9" id="WfF1I4h9X_" role="1_0LWR">
            <node concept="19SUe$" id="WfF1I4h9XA" role="19SJt6" />
          </node>
        </node>
      </node>
      <node concept="16N1iO" id="WfF1I4h9XB" role="22Mr8z" />
      <node concept="16NEbp" id="WfF1I4h9XC" role="3faCKd">
        <property role="TrG5h" value="emergencyButton" />
        <node concept="16NEbR" id="WfF1I4h9XD" role="16NEbj">
          <property role="TrG5h" value="setEmergency" />
        </node>
        <node concept="16NEbR" id="WfF1I4jIpk" role="16NEbj">
          <property role="TrG5h" value="release" />
        </node>
        <node concept="16Ny3_" id="WfF1I4h9XE" role="16NEbj">
          <ref role="16Ny3F" node="WfF1I4haJ_" resolve="safetyTeam" />
        </node>
        <node concept="16Ny3_" id="WfF1I4h_cZ" role="16NEbj">
          <ref role="16Ny3F" node="WfF1I4h9T1" resolve="liftControl" />
        </node>
      </node>
    </node>
    <node concept="3fbQ3u" id="WfF1I4h9Z5" role="3fbPIo">
      <property role="2DRQuN" value="1669835434796" />
      <property role="2DXwbs" value="rijo" />
      <property role="1ylvJX" value="Open Door Button" />
      <property role="TrG5h" value="openDoor" />
      <node concept="GmGrk" id="WfF1I4h9Z6" role="GmGcz">
        <node concept="1_0LV8" id="WfF1I4h9Z7" role="1_0VJ0">
          <node concept="19SGf9" id="WfF1I4h9Z8" role="1_0LWR">
            <node concept="19SUe$" id="WfF1I4h9Z9" role="19SJt6" />
          </node>
        </node>
      </node>
      <node concept="16N1iO" id="WfF1I4h9Za" role="22Mr8z" />
      <node concept="16NEbp" id="WfF1I4h9Zb" role="3faCKd">
        <property role="TrG5h" value="openDoor" />
        <node concept="16NEbR" id="WfF1I4h9Zc" role="16NEbj">
          <property role="TrG5h" value="openDoor" />
        </node>
        <node concept="16Ny3_" id="WfF1I4h9Zd" role="16NEbj">
          <ref role="16Ny3F" node="WfF1I4h9T1" resolve="liftControl" />
        </node>
      </node>
    </node>
    <node concept="3fbQ3u" id="WfF1I4ha13" role="3fbPIo">
      <property role="2DRQuN" value="1669835434796" />
      <property role="2DXwbs" value="rijo" />
      <property role="1ylvJX" value="Close Door Button" />
      <property role="TrG5h" value="closeDoor" />
      <node concept="GmGrk" id="WfF1I4ha14" role="GmGcz">
        <node concept="1_0LV8" id="WfF1I4ha15" role="1_0VJ0">
          <node concept="19SGf9" id="WfF1I4ha16" role="1_0LWR">
            <node concept="19SUe$" id="WfF1I4ha17" role="19SJt6" />
          </node>
        </node>
      </node>
      <node concept="16N1iO" id="WfF1I4ha18" role="22Mr8z" />
      <node concept="16NEbp" id="WfF1I4ha19" role="3faCKd">
        <property role="TrG5h" value="closeDoor" />
        <node concept="16NEbR" id="WfF1I4ha1a" role="16NEbj">
          <property role="TrG5h" value="closeDoor" />
        </node>
        <node concept="16Ny3_" id="WfF1I4ha1b" role="16NEbj">
          <ref role="16Ny3F" node="WfF1I4h9T1" resolve="liftControl" />
        </node>
      </node>
    </node>
    <node concept="3fbQ3u" id="WfF1I4ha4g" role="3fbPIo">
      <property role="2DRQuN" value="1669835434796" />
      <property role="2DXwbs" value="rijo" />
      <property role="1ylvJX" value="Door Closed Detection Sensor" />
      <property role="TrG5h" value="doorEOL" />
      <node concept="GmGrk" id="WfF1I4ha4h" role="GmGcz">
        <node concept="1_0LV8" id="WfF1I4ha4i" role="1_0VJ0">
          <node concept="19SGf9" id="WfF1I4ha4j" role="1_0LWR">
            <node concept="19SUe$" id="WfF1I4ha4k" role="19SJt6" />
          </node>
        </node>
      </node>
      <node concept="16N1iO" id="WfF1I4ha4l" role="22Mr8z" />
      <node concept="16NEbp" id="WfF1I4ha4m" role="3faCKd">
        <property role="TrG5h" value="doorEOL" />
        <node concept="16NEbR" id="WfF1I4ha4n" role="16NEbj">
          <property role="TrG5h" value="doorClosed" />
        </node>
        <node concept="16Ny3_" id="WfF1I4ha4o" role="16NEbj">
          <ref role="16Ny3F" node="WfF1I4h9T1" resolve="liftControl" />
        </node>
      </node>
    </node>
    <node concept="3fbQ3u" id="WfF1I4ha5f" role="3fbPIo">
      <property role="2DRQuN" value="1669835434796" />
      <property role="2DXwbs" value="rijo" />
      <property role="1ylvJX" value="Detection Barrier Sensor" />
      <property role="TrG5h" value="detectionBarrier" />
      <node concept="GmGrk" id="WfF1I4ha5g" role="GmGcz">
        <node concept="1_0LV8" id="WfF1I4ha5h" role="1_0VJ0">
          <node concept="19SGf9" id="WfF1I4ha5i" role="1_0LWR">
            <node concept="19SUe$" id="WfF1I4ha5j" role="19SJt6" />
          </node>
        </node>
      </node>
      <node concept="16N1iO" id="WfF1I4ha5k" role="22Mr8z" />
      <node concept="16NEbp" id="WfF1I4ha5l" role="3faCKd">
        <property role="TrG5h" value="detectionBarrier" />
        <node concept="16NEbR" id="WfF1I4ha5m" role="16NEbj">
          <property role="TrG5h" value="triggerDetection" />
        </node>
        <node concept="16Ny3_" id="WfF1I4ha5n" role="16NEbj">
          <ref role="16Ny3F" node="WfF1I4h9T1" resolve="liftControl" />
        </node>
      </node>
    </node>
    <node concept="3fbQ3u" id="WfF1I4ha6n" role="3fbPIo">
      <property role="2DRQuN" value="1669835434796" />
      <property role="2DXwbs" value="rijo" />
      <property role="1ylvJX" value="Weight Cell Sensor" />
      <property role="TrG5h" value="weightCell" />
      <node concept="GmGrk" id="WfF1I4ha6o" role="GmGcz">
        <node concept="1_0LV8" id="WfF1I4ha6p" role="1_0VJ0">
          <node concept="19SGf9" id="WfF1I4ha6q" role="1_0LWR">
            <node concept="19SUe$" id="WfF1I4ha6r" role="19SJt6" />
          </node>
        </node>
      </node>
      <node concept="16N1iO" id="WfF1I4ha6s" role="22Mr8z" />
      <node concept="16NEbp" id="WfF1I4ha6t" role="3faCKd">
        <property role="TrG5h" value="weightCell" />
        <node concept="16NEbR" id="WfF1I4ha6u" role="16NEbj">
          <property role="TrG5h" value="triggerWeight" />
        </node>
        <node concept="16Ny3_" id="WfF1I4ha6v" role="16NEbj">
          <ref role="16Ny3F" node="WfF1I4h9T1" resolve="liftControl" />
        </node>
      </node>
    </node>
    <node concept="3fbQ3u" id="WfF1I4ha7C" role="3fbPIo">
      <property role="2DRQuN" value="1669835434796" />
      <property role="2DXwbs" value="rijo" />
      <property role="1ylvJX" value="Floor Detection Sensor" />
      <property role="TrG5h" value="floorSensor" />
      <node concept="GmGrk" id="WfF1I4ha7D" role="GmGcz">
        <node concept="1_0LV8" id="WfF1I4ha7E" role="1_0VJ0">
          <node concept="19SGf9" id="WfF1I4ha7F" role="1_0LWR">
            <node concept="19SUe$" id="WfF1I4ha7G" role="19SJt6" />
          </node>
        </node>
      </node>
      <node concept="16N1iO" id="WfF1I4ha7H" role="22Mr8z" />
      <node concept="16NEbp" id="WfF1I4ha7I" role="3faCKd">
        <property role="TrG5h" value="floorSensor" />
        <node concept="16NEbR" id="WfF1I4ha7J" role="16NEbj">
          <property role="TrG5h" value="triggerFloor" />
        </node>
        <node concept="16Ny3_" id="WfF1I4ha7K" role="16NEbj">
          <ref role="16Ny3F" node="WfF1I4h9T1" resolve="liftControl" />
        </node>
      </node>
    </node>
    <node concept="3fbQ3u" id="WfF1I4ivUk" role="3fbPIo">
      <property role="2DRQuN" value="1669907278580" />
      <property role="2DXwbs" value="rijo" />
      <property role="1ylvJX" value="Motor Up" />
      <property role="TrG5h" value="motorUp" />
      <node concept="GmGrk" id="WfF1I4ivUm" role="GmGcz">
        <node concept="1_0LV8" id="WfF1I4ivUn" role="1_0VJ0">
          <node concept="19SGf9" id="WfF1I4ivUo" role="1_0LWR">
            <node concept="19SUe$" id="WfF1I4ivUp" role="19SJt6" />
          </node>
        </node>
      </node>
      <node concept="16N1iO" id="WfF1I4ivZ1" role="22Mr8z" />
      <node concept="16NEbp" id="WfF1I4ivZ6" role="3faCKd">
        <property role="TrG5h" value="motorUp" />
        <node concept="16NEbR" id="WfF1I4ivZ9" role="16NEbj">
          <property role="TrG5h" value="on" />
        </node>
        <node concept="16NEbR" id="WfF1I4jrYn" role="16NEbj">
          <property role="TrG5h" value="off" />
        </node>
        <node concept="16Ny3_" id="WfF1I4ivZe" role="16NEbj">
          <ref role="16Ny3F" node="WfF1I4h9T1" resolve="liftControl" />
        </node>
      </node>
    </node>
    <node concept="3fbQ3u" id="WfF1I4ivZy" role="3fbPIo">
      <property role="2DRQuN" value="1669907278580" />
      <property role="2DXwbs" value="rijo" />
      <property role="1ylvJX" value="Motor Down" />
      <property role="TrG5h" value="motorDown" />
      <node concept="GmGrk" id="WfF1I4ivZz" role="GmGcz">
        <node concept="1_0LV8" id="WfF1I4ivZ$" role="1_0VJ0">
          <node concept="19SGf9" id="WfF1I4ivZ_" role="1_0LWR">
            <node concept="19SUe$" id="WfF1I4ivZA" role="19SJt6" />
          </node>
        </node>
      </node>
      <node concept="16N1iO" id="WfF1I4ivZB" role="22Mr8z" />
      <node concept="16NEbp" id="WfF1I4ivZC" role="3faCKd">
        <property role="TrG5h" value="motorDown" />
        <node concept="16NEbR" id="WfF1I4jrYx" role="16NEbj">
          <property role="TrG5h" value="on" />
        </node>
        <node concept="16NEbR" id="WfF1I4jrYy" role="16NEbj">
          <property role="TrG5h" value="off" />
        </node>
        <node concept="16Ny3_" id="WfF1I4ivZE" role="16NEbj">
          <ref role="16Ny3F" node="WfF1I4h9T1" resolve="liftControl" />
        </node>
      </node>
    </node>
    <node concept="3fbQ3u" id="WfF1I4iw4Q" role="3fbPIo">
      <property role="2DRQuN" value="1669907278580" />
      <property role="2DXwbs" value="rijo" />
      <property role="1ylvJX" value="Motor Open Door" />
      <property role="TrG5h" value="motorOpenDoors" />
      <node concept="GmGrk" id="WfF1I4iw4R" role="GmGcz">
        <node concept="1_0LV8" id="WfF1I4iw4S" role="1_0VJ0">
          <node concept="19SGf9" id="WfF1I4iw4T" role="1_0LWR">
            <node concept="19SUe$" id="WfF1I4iw4U" role="19SJt6" />
          </node>
        </node>
      </node>
      <node concept="16N1iO" id="WfF1I4iw4V" role="22Mr8z" />
      <node concept="16NEbp" id="WfF1I4iw4W" role="3faCKd">
        <property role="TrG5h" value="motorOpenDoors" />
        <node concept="16NEbR" id="WfF1I4jrYA" role="16NEbj">
          <property role="TrG5h" value="on" />
        </node>
        <node concept="16NEbR" id="WfF1I4jrYB" role="16NEbj">
          <property role="TrG5h" value="off" />
        </node>
        <node concept="16Ny3_" id="WfF1I4iw4Y" role="16NEbj">
          <ref role="16Ny3F" node="WfF1I4h9T1" resolve="liftControl" />
        </node>
      </node>
    </node>
    <node concept="3fbQ3u" id="WfF1I4iw4Z" role="3fbPIo">
      <property role="2DRQuN" value="1669907278580" />
      <property role="2DXwbs" value="rijo" />
      <property role="1ylvJX" value="Motor Close Door" />
      <property role="TrG5h" value="motorCloseDoors" />
      <node concept="GmGrk" id="WfF1I4iw50" role="GmGcz">
        <node concept="1_0LV8" id="WfF1I4iw51" role="1_0VJ0">
          <node concept="19SGf9" id="WfF1I4iw52" role="1_0LWR">
            <node concept="19SUe$" id="WfF1I4iw53" role="19SJt6" />
          </node>
        </node>
      </node>
      <node concept="16N1iO" id="WfF1I4iw54" role="22Mr8z" />
      <node concept="16NEbp" id="WfF1I4iw55" role="3faCKd">
        <property role="TrG5h" value="motorCloseDoors" />
        <node concept="16NEbR" id="WfF1I4jrYF" role="16NEbj">
          <property role="TrG5h" value="on" />
        </node>
        <node concept="16NEbR" id="WfF1I4jrYG" role="16NEbj">
          <property role="TrG5h" value="off" />
        </node>
        <node concept="16Ny3_" id="WfF1I4iw57" role="16NEbj">
          <ref role="16Ny3F" node="WfF1I4h9T1" resolve="liftControl" />
        </node>
      </node>
    </node>
    <node concept="3fbQ3u" id="WfF1I4iXz4" role="3fbPIo">
      <property role="2DRQuN" value="1669909175471" />
      <property role="2DXwbs" value="rijo" />
      <property role="1ylvJX" value="Max Weight Alarm" />
      <property role="TrG5h" value="weightAlarm" />
      <node concept="GmGrk" id="WfF1I4iXz6" role="GmGcz">
        <node concept="1_0LV8" id="WfF1I4iXz7" role="1_0VJ0">
          <node concept="19SGf9" id="WfF1I4iXz8" role="1_0LWR">
            <node concept="19SUe$" id="WfF1I4iXz9" role="19SJt6" />
          </node>
        </node>
      </node>
      <node concept="16N1iO" id="WfF1I4iXDt" role="22Mr8z" />
      <node concept="16NEbp" id="WfF1I4iXHN" role="3faCKd">
        <property role="TrG5h" value="weightAlarm" />
        <node concept="16NEbR" id="WfF1I4jrYK" role="16NEbj">
          <property role="TrG5h" value="on" />
        </node>
        <node concept="16NEbR" id="WfF1I4jrYL" role="16NEbj">
          <property role="TrG5h" value="off" />
        </node>
        <node concept="16Ny3_" id="WfF1I4iXI7" role="16NEbj">
          <ref role="16Ny3F" node="WfF1I4h9T1" resolve="liftControl" />
        </node>
      </node>
    </node>
    <node concept="3fbQ3u" id="WfF1I4iXQU" role="3fbPIo">
      <property role="2DRQuN" value="1669909175471" />
      <property role="2DXwbs" value="rijo" />
      <property role="1ylvJX" value="Emergency Alarm" />
      <property role="TrG5h" value="emergencyAlarm" />
      <node concept="GmGrk" id="WfF1I4iXQV" role="GmGcz">
        <node concept="1_0LV8" id="WfF1I4iXQW" role="1_0VJ0">
          <node concept="19SGf9" id="WfF1I4iXQX" role="1_0LWR">
            <node concept="19SUe$" id="WfF1I4iXQY" role="19SJt6" />
          </node>
        </node>
      </node>
      <node concept="16N1iO" id="WfF1I4iXQZ" role="22Mr8z" />
      <node concept="16NEbp" id="WfF1I4iXR0" role="3faCKd">
        <property role="TrG5h" value="emergencyAlarm" />
        <node concept="16NEbR" id="WfF1I4jrYP" role="16NEbj">
          <property role="TrG5h" value="on" />
        </node>
        <node concept="16NEbR" id="WfF1I4jrYQ" role="16NEbj">
          <property role="TrG5h" value="off" />
        </node>
        <node concept="16Ny3_" id="WfF1I4iXR2" role="16NEbj">
          <ref role="16Ny3F" node="WfF1I4h9T1" resolve="liftControl" />
        </node>
      </node>
    </node>
    <node concept="3fbQ3u" id="WfF1I4mZM$" role="3fbPIo">
      <property role="2DRQuN" value="1669835104511" />
      <property role="2DXwbs" value="rijo" />
      <property role="1ylvJX" value="Ambient Lights" />
      <property role="TrG5h" value="ambientLight" />
      <node concept="GmGrk" id="WfF1I4mZM_" role="GmGcz">
        <node concept="1_0LV8" id="WfF1I4mZMA" role="1_0VJ0">
          <node concept="19SGf9" id="WfF1I4mZMB" role="1_0LWR">
            <node concept="19SUe$" id="WfF1I4mZMC" role="19SJt6" />
          </node>
        </node>
      </node>
      <node concept="16N1iO" id="WfF1I4mZMD" role="22Mr8z" />
      <node concept="16NEbp" id="WfF1I4mZME" role="3faCKd">
        <property role="TrG5h" value="ambientLight" />
        <node concept="16NEbR" id="WfF1I4mZMF" role="16NEbj">
          <property role="TrG5h" value="on" />
        </node>
        <node concept="16NEbR" id="WfF1I4mZPB" role="16NEbj">
          <property role="TrG5h" value="off" />
        </node>
        <node concept="16Ny3_" id="WfF1I4mZMG" role="16NEbj">
          <ref role="16Ny3F" node="WfF1I4h9T1" resolve="liftControl" />
        </node>
      </node>
    </node>
  </node>
  <node concept="3fbPIq" id="WfF1I4h9LU">
    <property role="TrG5h" value="Requirements" />
    <ref role="G9hjw" node="WfF1I4h9D1" resolve="DefaultDocConfig" />
    <node concept="OjmMv" id="WfF1I4h9LV" role="tLAhV">
      <node concept="19SGf9" id="WfF1I4h9LW" role="OjmMu">
        <node concept="19SUe$" id="WfF1I4h9LX" role="19SJt6" />
      </node>
    </node>
    <node concept="2RsZnQ" id="WfF1I4h9LY" role="2RsZnW" />
    <node concept="3GEVxB" id="WfF1I4h9Oe" role="1BwUYK">
      <ref role="3GEb4d" node="WfF1I4h9O7" resolve="UseCases" />
    </node>
    <node concept="3fbQ3u" id="WfF1I4hbDc" role="3fbPIo">
      <property role="2DRQuN" value="1669840083097" />
      <property role="2DXwbs" value="rijo" />
      <property role="1ylvJX" value="Lift Functionality Requirements" />
      <property role="TrG5h" value="liftFuncReq" />
      <node concept="22Mrfp" id="WfF1I4hbDd" role="22Mr8z" />
      <node concept="GmGrk" id="WfF1I4hbDe" role="GmGcz">
        <node concept="1_0LV8" id="WfF1I4hbDf" role="1_0VJ0">
          <node concept="19SGf9" id="WfF1I4hbDg" role="1_0LWR">
            <node concept="19SUe$" id="WfF1I4hbDh" role="19SJt6">
              <property role="19SUeA" value="Inside the lift, there must be a &quot;target floor&quot; button for selecting the destination floor and an &quot;emergency&quot; button to activate the emergency alarm inside, as well as a &quot;close door&quot; button and a &quot;open door&quot; button to close and open the door respectively." />
            </node>
          </node>
        </node>
      </node>
      <node concept="3fbQ3u" id="WfF1I4hbDW" role="3fbPAY">
        <property role="2DRQuN" value="1669840083097" />
        <property role="2DXwbs" value="rijo" />
        <property role="1ylvJX" value="Cabin Requirements" />
        <property role="TrG5h" value="cabinReq" />
        <node concept="22Mrfp" id="WfF1I4hbDX" role="22Mr8z" />
        <node concept="GmGrk" id="WfF1I4hbDY" role="GmGcz">
          <node concept="1_0LV8" id="WfF1I4hbDZ" role="1_0VJ0">
            <node concept="19SGf9" id="WfF1I4hbE0" role="1_0LWR">
              <node concept="19SUe$" id="WfF1I4hbE1" role="19SJt6">
                <property role="19SUeA" value="The lift must also have a movement detection barrier to detect a passage of an user when the doors are clossing, an weight cell sensor to check the total weight of the passengers, a sensor to detect if the doors are closed and floor display" />
              </node>
            </node>
          </node>
        </node>
      </node>
      <node concept="3fbQ3u" id="WfF1I4hbES" role="3fbPAY">
        <property role="2DRQuN" value="1669840083097" />
        <property role="2DXwbs" value="rijo" />
        <property role="1ylvJX" value="Floor Requirements" />
        <property role="TrG5h" value="floorReq" />
        <node concept="22Mrfp" id="WfF1I4hbET" role="22Mr8z" />
        <node concept="GmGrk" id="WfF1I4hbEU" role="GmGcz">
          <node concept="1_0LV8" id="WfF1I4hbEV" role="1_0VJ0">
            <node concept="19SGf9" id="WfF1I4hbEW" role="1_0LWR">
              <node concept="19SUe$" id="WfF1I4hbEX" role="19SJt6">
                <property role="19SUeA" value="Every floor must have a &quot;call lift&quot; button, a floor display and a movement display" />
              </node>
            </node>
          </node>
        </node>
      </node>
    </node>
    <node concept="3fbQ3u" id="WfF1I4hbpO" role="3fbPIo">
      <property role="2DRQuN" value="1669840083097" />
      <property role="2DXwbs" value="rijo" />
      <property role="1ylvJX" value="Lift Behaviour Requirements" />
      <property role="TrG5h" value="liftBehaviourReq" />
      <node concept="22Mrfp" id="WfF1I4hbpP" role="22Mr8z" />
      <node concept="GmGrk" id="WfF1I4hbpQ" role="GmGcz">
        <node concept="1_0LV8" id="WfF1I4hbq5" role="1_0VJ0">
          <node concept="19SGf9" id="WfF1I4hbq6" role="1_0LWR">
            <node concept="19SUe$" id="WfF1I4hbq7" role="19SJt6">
              <property role="19SUeA" value="The lift must be in a &quot;standby&quot; state after it is turned on" />
            </node>
          </node>
        </node>
      </node>
      <node concept="3fbQ3u" id="WfF1I4hbFK" role="3fbPAY">
        <property role="2DRQuN" value="1669840083097" />
        <property role="2DXwbs" value="rijo" />
        <property role="1ylvJX" value="StandBy Requirements" />
        <property role="TrG5h" value="standbyReq" />
        <node concept="22Mrfp" id="WfF1I4hbFL" role="22Mr8z" />
        <node concept="GmGrk" id="WfF1I4hbFM" role="GmGcz">
          <node concept="1_0LV8" id="WfF1I4hbFN" role="1_0VJ0">
            <node concept="19SGf9" id="WfF1I4hbFO" role="1_0LWR">
              <node concept="19SUe$" id="WfF1I4hbFP" role="19SJt6">
                <property role="19SUeA" value="While in the &quot;standby&quot; state, the lift must be stopped and waiting for a press of a &quot;call lift&quot; button by an user that is outside the lift or for a press of the &quot;open door&quot; button by an user that is inside the lift." />
              </node>
            </node>
          </node>
        </node>
      </node>
      <node concept="3fbQ3u" id="WfF1I4hbH4" role="3fbPAY">
        <property role="2DRQuN" value="1669840083097" />
        <property role="2DXwbs" value="rijo" />
        <property role="1ylvJX" value="Call Lift Requirements" />
        <property role="TrG5h" value="callReq" />
        <node concept="22Mrfp" id="WfF1I4hbH5" role="22Mr8z" />
        <node concept="GmGrk" id="WfF1I4hbH6" role="GmGcz">
          <node concept="1_0LV8" id="WfF1I4hbH7" role="1_0VJ0">
            <node concept="19SGf9" id="WfF1I4hbH8" role="1_0LWR">
              <node concept="19SUe$" id="WfF1I4hbH9" role="19SJt6">
                <property role="19SUeA" value="When the &quot;call lift&quot; button is pressed, the lift must movesup or down in the direction of the floor where the button was pressed." />
              </node>
            </node>
          </node>
        </node>
        <node concept="3fbQ3u" id="WfF1I4hbHm" role="3fbPAY">
          <property role="2DRQuN" value="1669840083097" />
          <property role="2DXwbs" value="rijo" />
          <property role="1ylvJX" value="Call Lift Requirements" />
          <property role="TrG5h" value="choseTargetReq" />
          <node concept="22Mrfp" id="WfF1I4hbHn" role="22Mr8z" />
          <node concept="GmGrk" id="WfF1I4hbHo" role="GmGcz">
            <node concept="1_0LV8" id="WfF1I4hbHp" role="1_0VJ0">
              <node concept="19SGf9" id="WfF1I4hbHq" role="1_0LWR">
                <node concept="19SUe$" id="WfF1I4hbHr" role="19SJt6">
                  <property role="19SUeA" value="When the lift arrives at the floor where the button was pressed, its doors must open so that the user can enter the lift, the doors will close and then the lift waits for the user to press the &quot;target floor&quot; button" />
                </node>
              </node>
            </node>
          </node>
          <node concept="3fbQ3u" id="WfF1I4hbHI" role="3fbPAY">
            <property role="2DRQuN" value="1669840083097" />
            <property role="2DXwbs" value="rijo" />
            <property role="1ylvJX" value="Call Lift Requirements" />
            <property role="TrG5h" value="choseTargetTimeoutReq" />
            <node concept="22Mrfp" id="WfF1I4hbHJ" role="22Mr8z" />
            <node concept="GmGrk" id="WfF1I4hbHK" role="GmGcz">
              <node concept="1_0LV8" id="WfF1I4hbHL" role="1_0VJ0">
                <node concept="19SGf9" id="WfF1I4hbHM" role="1_0LWR">
                  <node concept="19SUe$" id="WfF1I4hbHN" role="19SJt6">
                    <property role="19SUeA" value="The lift must have a timeout in this stage: if the &quot;target floor&quot; button is not pressed within the timeout, the lift closes the door and returns to the &quot;standby&quot; state." />
                  </node>
                </node>
              </node>
            </node>
          </node>
          <node concept="3fbQ3u" id="WfF1I4hbIc" role="3fbPAY">
            <property role="2DRQuN" value="1669840083097" />
            <property role="2DXwbs" value="rijo" />
            <property role="1ylvJX" value="Call Lift Requirements" />
            <property role="TrG5h" value="movingToFloorReq" />
            <node concept="22Mrfp" id="WfF1I4hbId" role="22Mr8z" />
            <node concept="GmGrk" id="WfF1I4hbIe" role="GmGcz">
              <node concept="1_0LV8" id="WfF1I4hbIf" role="1_0VJ0">
                <node concept="19SGf9" id="WfF1I4hbIg" role="1_0LWR">
                  <node concept="19SUe$" id="WfF1I4hbIh" role="19SJt6">
                    <property role="19SUeA" value="If the &quot;target floor&quot; button is pressed, the lift must go in the direction of the floor indicated by the &quot;target floor&quot; button." />
                  </node>
                </node>
              </node>
            </node>
          </node>
        </node>
      </node>
      <node concept="3fbQ3u" id="WfF1I4hbIK" role="3fbPAY">
        <property role="2DRQuN" value="1669840083097" />
        <property role="2DXwbs" value="rijo" />
        <property role="1ylvJX" value="Moving to Target Floor Requirements" />
        <property role="TrG5h" value="releaseStateReq" />
        <node concept="22Mrfp" id="WfF1I4hbIL" role="22Mr8z" />
        <node concept="GmGrk" id="WfF1I4hbIM" role="GmGcz">
          <node concept="1_0LV8" id="WfF1I4hbIN" role="1_0VJ0">
            <node concept="19SGf9" id="WfF1I4hbIO" role="1_0LWR">
              <node concept="19SUe$" id="WfF1I4hbIP" role="19SJt6">
                <property role="19SUeA" value="When the lift arrives to the floor where the button was pressed, it must stop and open the door, so that the user/users can exit the lift." />
              </node>
            </node>
          </node>
        </node>
        <node concept="3fbQ3u" id="WfF1I4hbJq" role="3fbPAY">
          <property role="2DRQuN" value="1669840083097" />
          <property role="2DXwbs" value="rijo" />
          <property role="1ylvJX" value="Moving to Target Floor Requirements" />
          <property role="TrG5h" value="transitionToStandbyReq" />
          <node concept="22Mrfp" id="WfF1I4hbJr" role="22Mr8z" />
          <node concept="GmGrk" id="WfF1I4hbJs" role="GmGcz">
            <node concept="1_0LV8" id="WfF1I4hbJt" role="1_0VJ0">
              <node concept="19SGf9" id="WfF1I4hbJu" role="1_0LWR">
                <node concept="19SUe$" id="WfF1I4hbJv" role="19SJt6">
                  <property role="19SUeA" value="The lift must have a timeout in this stage: after the timeout ends, the door must close and the lift must return to the &quot;standby&quot; state if there isn’t another target floor selected." />
                </node>
              </node>
            </node>
          </node>
        </node>
      </node>
      <node concept="3fbQ3u" id="WfF1I4hbKa" role="3fbPAY">
        <property role="2DRQuN" value="1669840083097" />
        <property role="2DXwbs" value="rijo" />
        <property role="1ylvJX" value="Open/Close Doors Requirements" />
        <property role="TrG5h" value="opencloseDoorsReq" />
        <node concept="22Mrfp" id="WfF1I4hbKb" role="22Mr8z" />
        <node concept="GmGrk" id="WfF1I4hbKc" role="GmGcz">
          <node concept="1_0LV8" id="WfF1I4hbKd" role="1_0VJ0">
            <node concept="19SGf9" id="WfF1I4hbKe" role="1_0LWR">
              <node concept="19SUe$" id="WfF1I4hbKf" role="19SJt6">
                <property role="19SUeA" value="When a user is inside the lift, he may press the &quot;close door&quot; or the &quot;open door&quot; button and the lift must do the corresponding action for these button, only if it is stopped at a floor." />
              </node>
            </node>
          </node>
        </node>
        <node concept="3fbQ3u" id="WfF1I4hbL0" role="3fbPAY">
          <property role="2DRQuN" value="1669840083097" />
          <property role="2DXwbs" value="rijo" />
          <property role="1ylvJX" value="Open/Close Doors Requirements" />
          <property role="TrG5h" value="openDoorTimeoutReq" />
          <node concept="22Mrfp" id="WfF1I4hbL1" role="22Mr8z" />
          <node concept="GmGrk" id="WfF1I4hbL2" role="GmGcz">
            <node concept="1_0LV8" id="WfF1I4hbL3" role="1_0VJ0">
              <node concept="19SGf9" id="WfF1I4hbL4" role="1_0LWR">
                <node concept="19SUe$" id="WfF1I4hbL5" role="19SJt6">
                  <property role="19SUeA" value="The &quot;open door&quot; button must always set a timeout. When the timeout ends, the lift must close the door." />
                </node>
              </node>
            </node>
          </node>
        </node>
      </node>
    </node>
    <node concept="3fbQ3u" id="WfF1I4hbD$" role="3fbPIo">
      <property role="2DRQuN" value="1669840083097" />
      <property role="2DXwbs" value="rijo" />
      <property role="1ylvJX" value="Lift Safety Requirements" />
      <property role="TrG5h" value="liftSafetyReq" />
      <node concept="22Mrfp" id="WfF1I4hbD_" role="22Mr8z" />
      <node concept="GmGrk" id="WfF1I4hbDA" role="GmGcz">
        <node concept="1_0LV8" id="WfF1I4hbDB" role="1_0VJ0">
          <node concept="19SGf9" id="WfF1I4hbDC" role="1_0LWR">
            <node concept="19SUe$" id="WfF1I4hbDD" role="19SJt6">
              <property role="19SUeA" value="The safety measurements must activate immediatly at any time." />
            </node>
          </node>
        </node>
      </node>
      <node concept="3fbQ3u" id="WfF1I4hbP2" role="3fbPAY">
        <property role="2DRQuN" value="1669840083097" />
        <property role="2DXwbs" value="rijo" />
        <property role="1ylvJX" value="Emergency Requirements" />
        <property role="TrG5h" value="emergencyReq" />
        <node concept="22Mrfp" id="WfF1I4hbP3" role="22Mr8z" />
        <node concept="GmGrk" id="WfF1I4hbP4" role="GmGcz">
          <node concept="1_0LV8" id="WfF1I4hbP5" role="1_0VJ0">
            <node concept="19SGf9" id="WfF1I4hbP6" role="1_0LWR">
              <node concept="19SUe$" id="WfF1I4hbP7" role="19SJt6">
                <property role="19SUeA" value="If the emergency buttons is pressed, the lift must enter the emergency state." />
              </node>
            </node>
          </node>
        </node>
        <node concept="3fbQ3u" id="WfF1I4hbQy" role="3fbPAY">
          <property role="2DRQuN" value="1669840083097" />
          <property role="2DXwbs" value="rijo" />
          <property role="1ylvJX" value="Emergency Requirements" />
          <property role="TrG5h" value="emergencyStateReq" />
          <node concept="22Mrfp" id="WfF1I4hbQz" role="22Mr8z" />
          <node concept="GmGrk" id="WfF1I4hbQ$" role="GmGcz">
            <node concept="1_0LV8" id="WfF1I4hbQ_" role="1_0VJ0">
              <node concept="19SGf9" id="WfF1I4hbQA" role="1_0LWR">
                <node concept="19SUe$" id="WfF1I4hbQB" role="19SJt6">
                  <property role="19SUeA" value="While in the emergency state, the lift must sound an alarm, call the security team and stop all motors." />
                </node>
              </node>
            </node>
          </node>
        </node>
        <node concept="3fbQ3u" id="WfF1I4hbTO" role="3fbPAY">
          <property role="2DRQuN" value="1669840083097" />
          <property role="2DXwbs" value="rijo" />
          <property role="1ylvJX" value="Emergency Requirements" />
          <property role="TrG5h" value="emergencyStateOUTReq" />
          <node concept="22Mrfp" id="WfF1I4hbTP" role="22Mr8z" />
          <node concept="GmGrk" id="WfF1I4hbTQ" role="GmGcz">
            <node concept="1_0LV8" id="WfF1I4hbTR" role="1_0VJ0">
              <node concept="19SGf9" id="WfF1I4hbTS" role="1_0LWR">
                <node concept="19SUe$" id="WfF1I4hbTT" role="19SJt6">
                  <property role="19SUeA" value="When the &quot;emergency button is released, the lift returnes to the standby state." />
                </node>
              </node>
            </node>
          </node>
        </node>
      </node>
      <node concept="3fbQ3u" id="WfF1I4hbS8" role="3fbPAY">
        <property role="2DRQuN" value="1669840083097" />
        <property role="2DXwbs" value="rijo" />
        <property role="1ylvJX" value="Capacity Requirements" />
        <property role="TrG5h" value="capacityReq" />
        <node concept="22Mrfp" id="WfF1I4hbS9" role="22Mr8z" />
        <node concept="GmGrk" id="WfF1I4hbSa" role="GmGcz">
          <node concept="1_0LV8" id="WfF1I4hbSb" role="1_0VJ0">
            <node concept="19SGf9" id="WfF1I4hbSc" role="1_0LWR">
              <node concept="19SUe$" id="WfF1I4hbSd" role="19SJt6">
                <property role="19SUeA" value="The doors must open if the total weight of the passengers is higher than its max capacity" />
              </node>
            </node>
          </node>
        </node>
      </node>
      <node concept="3fbQ3u" id="WfF1I4hbVA" role="3fbPAY">
        <property role="2DRQuN" value="1669840083097" />
        <property role="2DXwbs" value="rijo" />
        <property role="1ylvJX" value="Closing Doors Requirements" />
        <property role="TrG5h" value="detectionReq" />
        <node concept="22Mrfp" id="WfF1I4hbVB" role="22Mr8z" />
        <node concept="GmGrk" id="WfF1I4hbVC" role="GmGcz">
          <node concept="1_0LV8" id="WfF1I4hbVD" role="1_0VJ0">
            <node concept="19SGf9" id="WfF1I4hbVE" role="1_0LWR">
              <node concept="19SUe$" id="WfF1I4hbVF" role="19SJt6">
                <property role="19SUeA" value="The doors must open if any object passes through the detection barrier." />
              </node>
            </node>
          </node>
        </node>
      </node>
      <node concept="3fbQ3u" id="WfF1I4hcc2" role="3fbPAY">
        <property role="2DRQuN" value="1669840083097" />
        <property role="2DXwbs" value="rijo" />
        <property role="1ylvJX" value="Cabin Safety Requirements" />
        <property role="TrG5h" value="closeDoorsReq" />
        <node concept="22Mrfp" id="WfF1I4hcc3" role="22Mr8z" />
        <node concept="GmGrk" id="WfF1I4hcc4" role="GmGcz">
          <node concept="1_0LV8" id="WfF1I4hcc5" role="1_0VJ0">
            <node concept="19SGf9" id="WfF1I4hcc6" role="1_0LWR">
              <node concept="19SUe$" id="WfF1I4hcc7" role="19SJt6">
                <property role="19SUeA" value="The doors must remain locked when the lift is moving." />
              </node>
            </node>
          </node>
        </node>
      </node>
    </node>
  </node>
  <node concept="3fbPIq" id="WfF1I4h9O7">
    <property role="TrG5h" value="UseCases" />
    <ref role="G9hjw" node="WfF1I4h9D1" resolve="DefaultDocConfig" />
    <node concept="OjmMv" id="WfF1I4h9O8" role="tLAhV">
      <node concept="19SGf9" id="WfF1I4h9O9" role="OjmMu">
        <node concept="19SUe$" id="WfF1I4h9Oa" role="19SJt6" />
      </node>
    </node>
    <node concept="2RsZnQ" id="WfF1I4h9Ob" role="2RsZnW" />
    <node concept="3GEVxB" id="WfF1I4h9Og" role="1BwUYK">
      <ref role="3GEb4d" node="WfF1I4h9CW" resolve="Actuators" />
    </node>
    <node concept="3GEVxB" id="WfF1I4h9Ol" role="1BwUYK">
      <ref role="3GEb4d" node="WfF1I4h9Fc" resolve="Components" />
    </node>
    <node concept="3fbQ3u" id="WfF1I4i2uU" role="3fbPIo">
      <property role="2DRQuN" value="1669905667938" />
      <property role="2DXwbs" value="rijo" />
      <property role="1ylvJX" value="Use Case Call Lift" />
      <property role="TrG5h" value="callLiftToFloor" />
      <node concept="GmGrk" id="WfF1I4i2uW" role="GmGcz">
        <node concept="1_0LV8" id="WfF1I4i2uX" role="1_0VJ0">
          <node concept="19SGf9" id="WfF1I4i2uY" role="1_0LWR">
            <node concept="19SUe$" id="WfF1I4i2uZ" role="19SJt6">
              <property role="19SUeA" value="Use case of the system where the " />
            </node>
            <node concept="2oIDSw" id="WfF1I4i2va" role="19SJt6">
              <ref role="2wPqOu" node="WfF1I4h9RR" resolve="User" />
            </node>
            <node concept="19SUe$" id="WfF1I4i2v9" role="19SJt6">
              <property role="19SUeA" value=" uses the " />
            </node>
            <node concept="2oIDSw" id="WfF1I4i2vy" role="19SJt6">
              <ref role="2wPqOu" node="WfF1I4h_92" resolve="callLift" />
            </node>
            <node concept="19SUe$" id="WfF1I4i2vz" role="19SJt6">
              <property role="19SUeA" value=" button to call the lift by controlling the " />
            </node>
            <node concept="2oIDSw" id="WfF1I4i2v8" role="19SJt6">
              <ref role="2wPqOu" node="WfF1I4h9SG" resolve="liftControl" />
            </node>
            <node concept="19SUe$" id="WfF1I4i2vc" role="19SJt6">
              <property role="19SUeA" value="" />
            </node>
          </node>
        </node>
      </node>
      <node concept="4R1oT" id="WfF1I4i2uT" role="22Mr8z" />
      <node concept="oTeIi" id="WfF1I4ivQe" role="3faCKd" />
      <node concept="4R1oW" id="WfF1I4i2v6" role="3faCKd">
        <property role="TrG5h" value="callLiftToFloor" />
        <node concept="4RctY" id="WfF1I4i2vi" role="4Rctc">
          <node concept="16N2To" id="WfF1I4i2vj" role="4RctW">
            <ref role="16N2Tp" node="WfF1I4h9S5" resolve="User" />
          </node>
        </node>
        <node concept="4R9Ek" id="WfF1I4ivU0" role="4Rctc">
          <node concept="16N2To" id="WfF1I4ivU1" role="4R9Ej">
            <ref role="16N2Tp" node="WfF1I4h9T1" resolve="liftControl" />
          </node>
        </node>
      </node>
      <node concept="4R1oW" id="WfF1I4iw9Q" role="3faCKd">
        <property role="TrG5h" value="moveUp" />
        <node concept="4RctY" id="WfF1I4iw9R" role="4Rctc">
          <node concept="16N2To" id="WfF1I4iw9S" role="4RctW">
            <ref role="16N2Tp" node="WfF1I4h9T1" resolve="liftControl" />
          </node>
        </node>
        <node concept="4R9Ek" id="WfF1I4iw9T" role="4Rctc">
          <node concept="16N2To" id="WfF1I4iw9U" role="4R9Ej">
            <ref role="16N2Tp" node="WfF1I4ivZ6" resolve="motorUp" />
          </node>
        </node>
      </node>
      <node concept="4R1oW" id="WfF1I4iw9V" role="3faCKd">
        <property role="TrG5h" value="moveDown" />
        <node concept="4RctY" id="WfF1I4iw9W" role="4Rctc">
          <node concept="16N2To" id="WfF1I4iw9X" role="4RctW">
            <ref role="16N2Tp" node="WfF1I4h9T1" resolve="liftControl" />
          </node>
        </node>
        <node concept="4R9Ek" id="WfF1I4iw9Y" role="4Rctc">
          <node concept="16N2To" id="WfF1I4iw9Z" role="4R9Ej">
            <ref role="16N2Tp" node="WfF1I4ivZC" resolve="motorDown" />
          </node>
        </node>
      </node>
      <node concept="4R1oW" id="WfF1I4iwa0" role="3faCKd">
        <property role="TrG5h" value="inFloor" />
        <node concept="4RctY" id="WfF1I4iwa1" role="4Rctc">
          <node concept="16N2To" id="WfF1I4iwa2" role="4RctW">
            <ref role="16N2Tp" node="WfF1I4ivZC" resolve="motorDown" />
          </node>
        </node>
        <node concept="4RctY" id="WfF1I4iwa3" role="4Rctc">
          <node concept="16N2To" id="WfF1I4iwa4" role="4RctW">
            <ref role="16N2Tp" node="WfF1I4ivZ6" resolve="motorUp" />
          </node>
        </node>
        <node concept="4R9Ek" id="WfF1I4iwa5" role="4Rctc">
          <node concept="16N2To" id="WfF1I4iwa6" role="4R9Ej">
            <ref role="16N2Tp" node="WfF1I4iw4W" resolve="motorOpen" />
          </node>
        </node>
      </node>
      <node concept="3fbQ3u" id="WfF1I4jrBB" role="3fbPAY">
        <property role="2DRQuN" value="1669905667938" />
        <property role="2DXwbs" value="rijo" />
        <property role="1ylvJX" value="Scenario Call Lift to an Upper Floor" />
        <property role="TrG5h" value="callLiftUP" />
        <node concept="GmGrk" id="WfF1I4jrBC" role="GmGcz">
          <node concept="1_0LV8" id="WfF1I4jrBD" role="1_0VJ0">
            <node concept="19SGf9" id="WfF1I4jrBE" role="1_0LWR">
              <node concept="19SUe$" id="WfF1I4jshy" role="19SJt6">
                <property role="19SUeA" value="Scenario where the " />
              </node>
              <node concept="2oIDSw" id="WfF1I4juXd" role="19SJt6">
                <ref role="2wPqOu" node="WfF1I4h9RR" resolve="User" />
              </node>
              <node concept="19SUe$" id="WfF1I4juXe" role="19SJt6">
                <property role="19SUeA" value=" uses the " />
              </node>
              <node concept="2oIDSw" id="WfF1I4juXi" role="19SJt6">
                <ref role="2wPqOu" node="WfF1I4h_92" resolve="callLift" />
              </node>
              <node concept="19SUe$" id="WfF1I4juXj" role="19SJt6">
                <property role="19SUeA" value=" button to call the lift to an upper floor" />
              </node>
            </node>
          </node>
        </node>
        <node concept="16NtEM" id="WfF1I4jrI_" role="22Mr8z" />
        <node concept="16N2Tr" id="WfF1I4jrIB" role="3faCKd">
          <property role="TrG5h" value="callLift" />
          <node concept="16N2TF" id="WfF1I4jrJ5" role="16N2SG">
            <ref role="16N2TC" node="WfF1I4h9S5" resolve="User" />
            <node concept="16Nu5w" id="WfF1I4jrJv" role="16Nr0r">
              <ref role="16Np4H" node="WfF1I4h_99" resolve="callLiftToFloor" />
              <node concept="16N2To" id="WfF1I4jrJw" role="16NoOW">
                <ref role="16N2Tp" node="WfF1I4h_98" resolve="callLift" />
              </node>
            </node>
          </node>
          <node concept="16N2TF" id="WfF1I4jrKC" role="16N2SG">
            <ref role="16N2TC" node="WfF1I4h9T1" resolve="liftControl" />
            <node concept="16Mycm" id="WfF1I4jrLQ" role="16Nr0r">
              <ref role="16Np4H" node="WfF1I4jrLJ" resolve="receiveTargetFloor" />
            </node>
            <node concept="16Mycm" id="WfF1I4jugh" role="16Nr0r">
              <ref role="16Np4H" node="WfF1I4jufJ" resolve="receiveDoorEOLTrigger" />
            </node>
            <node concept="16Nu5w" id="WfF1I4jsi6" role="16Nr0r">
              <ref role="16Np4H" node="WfF1I4ivZ9" resolve="on" />
              <node concept="16N2To" id="WfF1I4jsi4" role="16NoOW">
                <ref role="16N2Tp" node="WfF1I4ivZ6" resolve="motorUp" />
              </node>
            </node>
            <node concept="16Nu5w" id="WfF1I4jsih" role="16Nr0r">
              <ref role="16Np4H" node="WfF1I4ha7J" resolve="triggerFloor" />
              <node concept="16N2To" id="WfF1I4jsif" role="16NoOW">
                <ref role="16N2Tp" node="WfF1I4ha7I" resolve="floorSensor" />
              </node>
            </node>
            <node concept="16Nu5w" id="WfF1I4jsiw" role="16Nr0r">
              <ref role="16Np4H" node="WfF1I4jrYn" resolve="off" />
              <node concept="16N2To" id="WfF1I4jsiu" role="16NoOW">
                <ref role="16N2Tp" node="WfF1I4ivZ6" resolve="motorUp" />
              </node>
            </node>
            <node concept="16Mycm" id="WfF1I4jBlD" role="16Nr0r">
              <ref role="16Np4H" node="WfF1I4j_nS" resolve="timeoutRelease" />
            </node>
            <node concept="16Nu5w" id="WfF1I4jsiN" role="16Nr0r">
              <ref role="16Np4H" node="WfF1I4jrYA" resolve="on" />
              <node concept="16N2To" id="WfF1I4jsiL" role="16NoOW">
                <ref role="16N2Tp" node="WfF1I4iw4W" resolve="motorOpenDoors" />
              </node>
            </node>
          </node>
        </node>
      </node>
      <node concept="3fbQ3u" id="WfF1I4jupS" role="3fbPAY">
        <property role="2DRQuN" value="1669905667938" />
        <property role="2DXwbs" value="rijo" />
        <property role="1ylvJX" value="Scenario Call Lift to an Lower Floor" />
        <property role="TrG5h" value="callLiftDOWN" />
        <node concept="GmGrk" id="WfF1I4jupT" role="GmGcz">
          <node concept="1_0LV8" id="WfF1I4jupU" role="1_0VJ0">
            <node concept="19SGf9" id="WfF1I4jupV" role="1_0LWR">
              <node concept="19SUe$" id="WfF1I4jupW" role="19SJt6">
                <property role="19SUeA" value="Scenario where the " />
              </node>
              <node concept="2oIDSw" id="WfF1I4juXp" role="19SJt6">
                <ref role="2wPqOu" node="WfF1I4h9RR" resolve="User" />
              </node>
              <node concept="19SUe$" id="WfF1I4juXq" role="19SJt6">
                <property role="19SUeA" value=" uses the " />
              </node>
              <node concept="2oIDSw" id="WfF1I4juXu" role="19SJt6">
                <ref role="2wPqOu" node="WfF1I4h_92" resolve="callLift" />
              </node>
              <node concept="19SUe$" id="WfF1I4juXv" role="19SJt6">
                <property role="19SUeA" value=" button to call the lift to an lower floor" />
              </node>
            </node>
          </node>
        </node>
        <node concept="16NtEM" id="WfF1I4jupX" role="22Mr8z" />
        <node concept="16N2Tr" id="WfF1I4jupY" role="3faCKd">
          <property role="TrG5h" value="callLift" />
          <node concept="16N2TF" id="WfF1I4jupZ" role="16N2SG">
            <ref role="16N2TC" node="WfF1I4h9S5" resolve="User" />
            <node concept="16Nu5w" id="WfF1I4juq0" role="16Nr0r">
              <ref role="16Np4H" node="WfF1I4h_99" resolve="sendTargetFloor" />
              <node concept="16N2To" id="WfF1I4juq1" role="16NoOW">
                <ref role="16N2Tp" node="WfF1I4h_98" resolve="callLift" />
              </node>
            </node>
          </node>
          <node concept="16N2TF" id="WfF1I4juq2" role="16N2SG">
            <ref role="16N2TC" node="WfF1I4h9T1" resolve="liftControl" />
            <node concept="16Mycm" id="WfF1I4juq3" role="16Nr0r">
              <ref role="16Np4H" node="WfF1I4jrLJ" resolve="receiveTargetFloor" />
            </node>
            <node concept="16Mycm" id="WfF1I4juq4" role="16Nr0r">
              <ref role="16Np4H" node="WfF1I4jufJ" resolve="receiveDoorEOLTrigger" />
            </node>
            <node concept="16Nu5w" id="WfF1I4juq5" role="16Nr0r">
              <ref role="16Np4H" node="WfF1I4jrYx" resolve="onp" />
              <node concept="16N2To" id="WfF1I4juq6" role="16NoOW">
                <ref role="16N2Tp" node="WfF1I4ivZC" resolve="motorDown" />
              </node>
            </node>
            <node concept="16Nu5w" id="WfF1I4juq7" role="16Nr0r">
              <ref role="16Np4H" node="WfF1I4ha7J" resolve="triggerFloor" />
              <node concept="16N2To" id="WfF1I4juq8" role="16NoOW">
                <ref role="16N2Tp" node="WfF1I4ha7I" resolve="floorSensor" />
              </node>
            </node>
            <node concept="16Nu5w" id="WfF1I4juq9" role="16Nr0r">
              <ref role="16Np4H" node="WfF1I4jrYy" resolve="off" />
              <node concept="16N2To" id="WfF1I4juqa" role="16NoOW">
                <ref role="16N2Tp" node="WfF1I4ivZC" resolve="motorDown" />
              </node>
            </node>
            <node concept="16Mycm" id="WfF1I4jBm4" role="16Nr0r">
              <ref role="16Np4H" node="WfF1I4j_nS" resolve="timeoutRelease" />
            </node>
            <node concept="16Nu5w" id="WfF1I4juqb" role="16Nr0r">
              <ref role="16Np4H" node="WfF1I4jrYA" resolve="on" />
              <node concept="16N2To" id="WfF1I4juqc" role="16NoOW">
                <ref role="16N2Tp" node="WfF1I4iw4W" resolve="motorOpenDoors" />
              </node>
            </node>
          </node>
        </node>
      </node>
    </node>
    <node concept="3fbQ3u" id="WfF1I4iw2M" role="3fbPIo">
      <property role="2DRQuN" value="1669905667938" />
      <property role="2DXwbs" value="rijo" />
      <property role="1ylvJX" value="Use Case Select Target Floor" />
      <property role="TrG5h" value="selectFloor" />
      <node concept="GmGrk" id="WfF1I4iw2N" role="GmGcz">
        <node concept="1_0LV8" id="WfF1I4iw2O" role="1_0VJ0">
          <node concept="19SGf9" id="WfF1I4iw2P" role="1_0LWR">
            <node concept="19SUe$" id="WfF1I4iw2Q" role="19SJt6">
              <property role="19SUeA" value="Use case where the " />
            </node>
            <node concept="2oIDSw" id="WfF1I4iw2R" role="19SJt6">
              <ref role="2wPqOu" node="WfF1I4h9RR" resolve="User" />
            </node>
            <node concept="19SUe$" id="WfF1I4iw2S" role="19SJt6">
              <property role="19SUeA" value=" uses the " />
            </node>
            <node concept="2oIDSw" id="WfF1I4iw2T" role="19SJt6">
              <ref role="2wPqOu" node="WfF1I4h9Vz" resolve="targetFloor" />
            </node>
            <node concept="19SUe$" id="WfF1I4iw2U" role="19SJt6">
              <property role="19SUeA" value=" button to send the lift to the target Floor by controlling the " />
            </node>
            <node concept="2oIDSw" id="WfF1I4iw2V" role="19SJt6">
              <ref role="2wPqOu" node="WfF1I4h9SG" resolve="liftControl" />
            </node>
            <node concept="19SUe$" id="WfF1I4iw2W" role="19SJt6">
              <property role="19SUeA" value="" />
            </node>
          </node>
        </node>
      </node>
      <node concept="4R1oT" id="WfF1I4iw2X" role="22Mr8z" />
      <node concept="oTeIi" id="WfF1I4iw2Y" role="3faCKd" />
      <node concept="4R1oW" id="WfF1I4iw2Z" role="3faCKd">
        <property role="TrG5h" value="selectFloor" />
        <node concept="4RctY" id="WfF1I4iw30" role="4Rctc">
          <node concept="16N2To" id="WfF1I4iw31" role="4RctW">
            <ref role="16N2Tp" node="WfF1I4h9S5" resolve="User" />
          </node>
        </node>
        <node concept="4R9Ek" id="WfF1I4iw32" role="4Rctc">
          <node concept="16N2To" id="WfF1I4iw33" role="4R9Ej">
            <ref role="16N2Tp" node="WfF1I4h9T1" resolve="liftControl" />
          </node>
        </node>
      </node>
      <node concept="4R1oW" id="WfF1I4iw87" role="3faCKd">
        <property role="TrG5h" value="closeDoor" />
        <node concept="4RctY" id="WfF1I4iw88" role="4Rctc">
          <node concept="16N2To" id="WfF1I4iw89" role="4RctW">
            <ref role="16N2Tp" node="WfF1I4h9T1" resolve="liftControl" />
          </node>
        </node>
        <node concept="4R9Ek" id="WfF1I4iw8a" role="4Rctc">
          <node concept="16N2To" id="WfF1I4iw8b" role="4R9Ej">
            <ref role="16N2Tp" node="WfF1I4iw55" resolve="motorClose" />
          </node>
        </node>
      </node>
      <node concept="4R1oW" id="WfF1I4iw34" role="3faCKd">
        <property role="TrG5h" value="moveUp2Target" />
        <node concept="4RctY" id="WfF1I4iw35" role="4Rctc">
          <node concept="16N2To" id="WfF1I4iw36" role="4RctW">
            <ref role="16N2Tp" node="WfF1I4iw55" resolve="motorClose" />
          </node>
        </node>
        <node concept="4R9Ek" id="WfF1I4iw37" role="4Rctc">
          <node concept="16N2To" id="WfF1I4iw38" role="4R9Ej">
            <ref role="16N2Tp" node="WfF1I4ivZ6" resolve="motorUp" />
          </node>
        </node>
      </node>
      <node concept="4R1oW" id="WfF1I4iw9a" role="3faCKd">
        <property role="TrG5h" value="moveDown2Target" />
        <node concept="4RctY" id="WfF1I4iw9b" role="4Rctc">
          <node concept="16N2To" id="WfF1I4iw9c" role="4RctW">
            <ref role="16N2Tp" node="WfF1I4iw55" resolve="motorClose" />
          </node>
        </node>
        <node concept="4R9Ek" id="WfF1I4iw9d" role="4Rctc">
          <node concept="16N2To" id="WfF1I4iw9e" role="4R9Ej">
            <ref role="16N2Tp" node="WfF1I4ivZC" resolve="motorDown" />
          </node>
        </node>
      </node>
      <node concept="4R1oW" id="WfF1I4iw3X" role="3faCKd">
        <property role="TrG5h" value="inFloor" />
        <node concept="4RctY" id="WfF1I4iw3Y" role="4Rctc">
          <node concept="16N2To" id="WfF1I4iw3Z" role="4RctW">
            <ref role="16N2Tp" node="WfF1I4ivZC" resolve="motorDown" />
          </node>
        </node>
        <node concept="4RctY" id="WfF1I4iw4w" role="4Rctc">
          <node concept="16N2To" id="WfF1I4iw4y" role="4RctW">
            <ref role="16N2Tp" node="WfF1I4ivZ6" resolve="motorUp" />
          </node>
        </node>
        <node concept="4R9Ek" id="WfF1I4iw7c" role="4Rctc">
          <node concept="16N2To" id="WfF1I4iw7e" role="4R9Ej">
            <ref role="16N2Tp" node="WfF1I4iw4W" resolve="motorOpen" />
          </node>
        </node>
      </node>
      <node concept="3fbQ3u" id="WfF1I4juH8" role="3fbPAY">
        <property role="2DRQuN" value="1669905667938" />
        <property role="2DXwbs" value="rijo" />
        <property role="1ylvJX" value="Scenario Target Floor Above" />
        <property role="TrG5h" value="goToUpFloor" />
        <node concept="GmGrk" id="WfF1I4juH9" role="GmGcz">
          <node concept="1_0LV8" id="WfF1I4juHa" role="1_0VJ0">
            <node concept="19SGf9" id="WfF1I4juHb" role="1_0LWR">
              <node concept="19SUe$" id="WfF1I4juHc" role="19SJt6">
                <property role="19SUeA" value="Scenario where the " />
              </node>
              <node concept="2oIDSw" id="WfF1I4juX_" role="19SJt6">
                <ref role="2wPqOu" node="WfF1I4h9RR" resolve="User" />
              </node>
              <node concept="19SUe$" id="WfF1I4juXA" role="19SJt6">
                <property role="19SUeA" value=" uses the " />
              </node>
              <node concept="2oIDSw" id="WfF1I4juXE" role="19SJt6">
                <ref role="2wPqOu" node="WfF1I4h_92" resolve="callLift" />
              </node>
              <node concept="19SUe$" id="WfF1I4juXF" role="19SJt6">
                <property role="19SUeA" value=" to go to an upper floor" />
              </node>
            </node>
          </node>
        </node>
        <node concept="16NtEM" id="WfF1I4juHd" role="22Mr8z" />
        <node concept="16N2Tr" id="WfF1I4juHe" role="3faCKd">
          <property role="TrG5h" value="goToUpFloor" />
          <node concept="16N2TF" id="WfF1I4juHf" role="16N2SG">
            <ref role="16N2TC" node="WfF1I4h9S5" resolve="User" />
            <node concept="16Nu5w" id="WfF1I4juHg" role="16Nr0r">
              <ref role="16Np4H" node="WfF1I4h9X9" resolve="selectTargetFloor" />
              <node concept="16N2To" id="WfF1I4juHh" role="16NoOW">
                <ref role="16N2Tp" node="WfF1I4h9X6" resolve="targetFloor" />
              </node>
            </node>
          </node>
          <node concept="16N2TF" id="WfF1I4juHi" role="16N2SG">
            <ref role="16N2TC" node="WfF1I4h9T1" resolve="liftControl" />
            <node concept="16Mycm" id="WfF1I4juHj" role="16Nr0r">
              <ref role="16Np4H" node="WfF1I4jrLJ" resolve="receiveTargetFloor" />
            </node>
            <node concept="16Mycm" id="WfF1I4juHk" role="16Nr0r">
              <ref role="16Np4H" node="WfF1I4jufJ" resolve="receiveDoorEOLTrigger" />
            </node>
            <node concept="16Nu5w" id="WfF1I4juHl" role="16Nr0r">
              <ref role="16Np4H" node="WfF1I4ivZ9" resolve="on" />
              <node concept="16N2To" id="WfF1I4juHm" role="16NoOW">
                <ref role="16N2Tp" node="WfF1I4ivZ6" resolve="motorUp" />
              </node>
            </node>
            <node concept="16Nu5w" id="WfF1I4juHn" role="16Nr0r">
              <ref role="16Np4H" node="WfF1I4ha7J" resolve="triggerFloor" />
              <node concept="16N2To" id="WfF1I4juHo" role="16NoOW">
                <ref role="16N2Tp" node="WfF1I4ha7I" resolve="floorSensor" />
              </node>
            </node>
            <node concept="16Nu5w" id="WfF1I4juHp" role="16Nr0r">
              <ref role="16Np4H" node="WfF1I4jrYn" resolve="off" />
              <node concept="16N2To" id="WfF1I4juHq" role="16NoOW">
                <ref role="16N2Tp" node="WfF1I4ivZ6" resolve="motorUp" />
              </node>
            </node>
            <node concept="16Mycm" id="WfF1I4jBmV" role="16Nr0r">
              <ref role="16Np4H" node="WfF1I4j_nS" resolve="timeoutRelease" />
            </node>
            <node concept="16Nu5w" id="WfF1I4juHr" role="16Nr0r">
              <ref role="16Np4H" node="WfF1I4jrYA" resolve="on" />
              <node concept="16N2To" id="WfF1I4juHs" role="16NoOW">
                <ref role="16N2Tp" node="WfF1I4iw4W" resolve="motorOpenDoors" />
              </node>
            </node>
            <node concept="16Mycm" id="WfF1I4jBnk" role="16Nr0r">
              <ref role="16Np4H" node="WfF1I4jBl4" resolve="timeoutOpenDoors" />
            </node>
            <node concept="16Nu5w" id="WfF1I4jBnJ" role="16Nr0r">
              <ref role="16Np4H" node="WfF1I4jrYF" resolve="on" />
              <node concept="16N2To" id="WfF1I4jBnK" role="16NoOW">
                <ref role="16N2Tp" node="WfF1I4iw55" resolve="motorCloseDoors" />
              </node>
            </node>
          </node>
        </node>
      </node>
      <node concept="3fbQ3u" id="WfF1I4jBpZ" role="3fbPAY">
        <property role="2DRQuN" value="1669905667938" />
        <property role="2DXwbs" value="rijo" />
        <property role="1ylvJX" value="Scenario Target Floor Bellow" />
        <property role="TrG5h" value="goToDownFloor" />
        <node concept="GmGrk" id="WfF1I4jBq0" role="GmGcz">
          <node concept="1_0LV8" id="WfF1I4jBq1" role="1_0VJ0">
            <node concept="19SGf9" id="WfF1I4jBq2" role="1_0LWR">
              <node concept="19SUe$" id="WfF1I4jBq3" role="19SJt6">
                <property role="19SUeA" value="Scenario where the " />
              </node>
              <node concept="2oIDSw" id="WfF1I4jBq4" role="19SJt6">
                <ref role="2wPqOu" node="WfF1I4h9RR" resolve="User" />
              </node>
              <node concept="19SUe$" id="WfF1I4jBq5" role="19SJt6">
                <property role="19SUeA" value=" uses the " />
              </node>
              <node concept="2oIDSw" id="WfF1I4jBq6" role="19SJt6">
                <ref role="2wPqOu" node="WfF1I4h_92" resolve="callLift" />
              </node>
              <node concept="19SUe$" id="WfF1I4jBq7" role="19SJt6">
                <property role="19SUeA" value=" to go to an lower floor" />
              </node>
            </node>
          </node>
        </node>
        <node concept="16NtEM" id="WfF1I4jBq8" role="22Mr8z" />
        <node concept="16N2Tr" id="WfF1I4jBq9" role="3faCKd">
          <property role="TrG5h" value="goToDownFloor" />
          <node concept="16N2TF" id="WfF1I4jBqa" role="16N2SG">
            <ref role="16N2TC" node="WfF1I4h9S5" resolve="User" />
            <node concept="16Nu5w" id="WfF1I4jBqb" role="16Nr0r">
              <ref role="16Np4H" node="WfF1I4h9X9" resolve="selectTargetFloor" />
              <node concept="16N2To" id="WfF1I4jBqc" role="16NoOW">
                <ref role="16N2Tp" node="WfF1I4h9X6" resolve="targetFloor" />
              </node>
            </node>
          </node>
          <node concept="16N2TF" id="WfF1I4jBqd" role="16N2SG">
            <ref role="16N2TC" node="WfF1I4h9T1" resolve="liftControl" />
            <node concept="16Mycm" id="WfF1I4jBqe" role="16Nr0r">
              <ref role="16Np4H" node="WfF1I4jrLJ" resolve="receiveTargetFloor" />
            </node>
            <node concept="16Mycm" id="WfF1I4jBqf" role="16Nr0r">
              <ref role="16Np4H" node="WfF1I4jufJ" resolve="receiveDoorEOLTrigger" />
            </node>
            <node concept="16Nu5w" id="WfF1I4jBqg" role="16Nr0r">
              <ref role="16Np4H" node="WfF1I4jrYx" resolve="on" />
              <node concept="16N2To" id="WfF1I4jBqh" role="16NoOW">
                <ref role="16N2Tp" node="WfF1I4ivZC" resolve="motorDown" />
              </node>
            </node>
            <node concept="16Nu5w" id="WfF1I4jBqi" role="16Nr0r">
              <ref role="16Np4H" node="WfF1I4ha7J" resolve="triggerFloor" />
              <node concept="16N2To" id="WfF1I4jBqj" role="16NoOW">
                <ref role="16N2Tp" node="WfF1I4ha7I" resolve="floorSensor" />
              </node>
            </node>
            <node concept="16Nu5w" id="WfF1I4jBqk" role="16Nr0r">
              <ref role="16Np4H" node="WfF1I4jrYy" resolve="off" />
              <node concept="16N2To" id="WfF1I4jBql" role="16NoOW">
                <ref role="16N2Tp" node="WfF1I4ivZC" resolve="motorDown" />
              </node>
            </node>
            <node concept="16Mycm" id="WfF1I4jBqm" role="16Nr0r">
              <ref role="16Np4H" node="WfF1I4j_nS" resolve="timeoutRelease" />
            </node>
            <node concept="16Nu5w" id="WfF1I4jBqn" role="16Nr0r">
              <ref role="16Np4H" node="WfF1I4jrYA" resolve="on" />
              <node concept="16N2To" id="WfF1I4jBqo" role="16NoOW">
                <ref role="16N2Tp" node="WfF1I4iw4W" resolve="motorOpenDoors" />
              </node>
            </node>
            <node concept="16Mycm" id="WfF1I4jBqp" role="16Nr0r">
              <ref role="16Np4H" node="WfF1I4jBl4" resolve="timeoutOpenDoors" />
            </node>
            <node concept="16Nu5w" id="WfF1I4jBqq" role="16Nr0r">
              <ref role="16Np4H" node="WfF1I4jrYF" resolve="on" />
              <node concept="16N2To" id="WfF1I4jBqr" role="16NoOW">
                <ref role="16N2Tp" node="WfF1I4iw55" resolve="motorCloseDoors" />
              </node>
            </node>
          </node>
        </node>
      </node>
    </node>
    <node concept="3fbQ3u" id="WfF1I4iXTj" role="3fbPIo">
      <property role="2DRQuN" value="1669905667938" />
      <property role="2DXwbs" value="rijo" />
      <property role="1ylvJX" value="Use Case Emergency System" />
      <property role="TrG5h" value="emergency" />
      <node concept="GmGrk" id="WfF1I4iXTk" role="GmGcz">
        <node concept="1_0LV8" id="WfF1I4iXTl" role="1_0VJ0">
          <node concept="19SGf9" id="WfF1I4iXTm" role="1_0LWR">
            <node concept="19SUe$" id="WfF1I4iXTn" role="19SJt6">
              <property role="19SUeA" value="Use case where the " />
            </node>
            <node concept="2oIDSw" id="WfF1I4iXTo" role="19SJt6">
              <ref role="2wPqOu" node="WfF1I4h9RR" resolve="User" />
            </node>
            <node concept="19SUe$" id="WfF1I4iXTp" role="19SJt6">
              <property role="19SUeA" value=" uses the " />
            </node>
            <node concept="2oIDSw" id="WfF1I4iXTq" role="19SJt6">
              <ref role="2wPqOu" node="WfF1I4h9Xy" resolve="emergencyButton" />
            </node>
            <node concept="19SUe$" id="WfF1I4iXTr" role="19SJt6">
              <property role="19SUeA" value=" button. The " />
            </node>
            <node concept="2oIDSw" id="WfF1I4iXVI" role="19SJt6">
              <ref role="2wPqOu" node="WfF1I4iXQU" resolve="emergencyAlarm" />
            </node>
            <node concept="19SUe$" id="WfF1I4iXVJ" role="19SJt6">
              <property role="19SUeA" value=" will activate, the " />
            </node>
            <node concept="2oIDSw" id="WfF1I4iXXd" role="19SJt6">
              <ref role="2wPqOu" node="WfF1I4h9V8" resolve="safetyTeam" />
            </node>
            <node concept="19SUe$" id="WfF1I4iXXr" role="19SJt6">
              <property role="19SUeA" value=" will be called and both " />
            </node>
            <node concept="2oIDSw" id="WfF1I4iXWG" role="19SJt6">
              <ref role="2wPqOu" node="WfF1I4ivUk" resolve="motorUp" />
            </node>
            <node concept="19SUe$" id="WfF1I4iXWH" role="19SJt6">
              <property role="19SUeA" value=" and " />
            </node>
            <node concept="2oIDSw" id="WfF1I4iXWV" role="19SJt6">
              <ref role="2wPqOu" node="WfF1I4ivZy" resolve="motorDown" />
            </node>
            <node concept="19SUe$" id="WfF1I4iXWW" role="19SJt6">
              <property role="19SUeA" value=" will stop.&#10;Later the " />
            </node>
            <node concept="2oIDSw" id="WfF1I4iXWf" role="19SJt6">
              <ref role="2wPqOu" node="WfF1I4h9V8" resolve="safetyTeam" />
            </node>
            <node concept="19SUe$" id="WfF1I4iXWg" role="19SJt6">
              <property role="19SUeA" value=" will deactivate the emergency status" />
            </node>
          </node>
        </node>
      </node>
      <node concept="4R1oT" id="WfF1I4iXTu" role="22Mr8z" />
      <node concept="oTeIi" id="WfF1I4iXTv" role="3faCKd" />
      <node concept="4R1oW" id="WfF1I4iXTw" role="3faCKd">
        <property role="TrG5h" value="emergencySet" />
        <node concept="4RctY" id="WfF1I4iXTx" role="4Rctc">
          <node concept="16N2To" id="WfF1I4iXTy" role="4RctW">
            <ref role="16N2Tp" node="WfF1I4h9S5" resolve="User" />
          </node>
        </node>
        <node concept="4R9Ek" id="WfF1I4iXTz" role="4Rctc">
          <node concept="16N2To" id="WfF1I4iXT$" role="4R9Ej">
            <ref role="16N2Tp" node="WfF1I4h9T1" resolve="liftControl" />
          </node>
        </node>
      </node>
      <node concept="4R1oW" id="WfF1I4iXT_" role="3faCKd">
        <property role="TrG5h" value="callSafetyTeam" />
        <node concept="4RctY" id="WfF1I4iXTA" role="4Rctc">
          <node concept="16N2To" id="WfF1I4iXTB" role="4RctW">
            <ref role="16N2Tp" node="WfF1I4h9T1" resolve="liftControl" />
          </node>
        </node>
        <node concept="4R9Ek" id="WfF1I4iXTC" role="4Rctc">
          <node concept="16N2To" id="WfF1I4iXTD" role="4R9Ej">
            <ref role="16N2Tp" node="WfF1I4haJ_" resolve="safetyTeam" />
          </node>
        </node>
      </node>
      <node concept="4R1oW" id="WfF1I4iXTE" role="3faCKd">
        <property role="TrG5h" value="soundEmergencyAlarm" />
        <node concept="4RctY" id="WfF1I4iXTF" role="4Rctc">
          <node concept="16N2To" id="WfF1I4iXTG" role="4RctW">
            <ref role="16N2Tp" node="WfF1I4h9T1" resolve="liftControl" />
          </node>
        </node>
        <node concept="4R9Ek" id="WfF1I4iXTH" role="4Rctc">
          <node concept="16N2To" id="WfF1I4iXTI" role="4R9Ej">
            <ref role="16N2Tp" node="WfF1I4iXR0" resolve="emergencyAlarm" />
          </node>
        </node>
      </node>
      <node concept="4R1oW" id="WfF1I4iY1m" role="3faCKd">
        <property role="TrG5h" value="stopMotors" />
        <node concept="4RctY" id="WfF1I4iY1n" role="4Rctc">
          <node concept="16N2To" id="WfF1I4iY1o" role="4RctW">
            <ref role="16N2Tp" node="WfF1I4h9T1" resolve="liftControl" />
          </node>
        </node>
        <node concept="4R9Ek" id="WfF1I4iY1p" role="4Rctc">
          <node concept="16N2To" id="WfF1I4iY1q" role="4R9Ej">
            <ref role="16N2Tp" node="WfF1I4ivZ6" resolve="motorUp" />
          </node>
        </node>
        <node concept="4R9Ek" id="WfF1I4iY1K" role="4Rctc">
          <node concept="16N2To" id="WfF1I4iY1L" role="4R9Ej">
            <ref role="16N2Tp" node="WfF1I4ivZC" resolve="motorDown" />
          </node>
        </node>
      </node>
      <node concept="4R1oW" id="WfF1I4iY5L" role="3faCKd">
        <property role="TrG5h" value="resetAlarm" />
        <node concept="4RctY" id="WfF1I4iY5M" role="4Rctc">
          <node concept="16N2To" id="WfF1I4iY5N" role="4RctW">
            <ref role="16N2Tp" node="WfF1I4haJ_" resolve="safetyTeam" />
          </node>
        </node>
        <node concept="4R9Ek" id="WfF1I4iY5O" role="4Rctc">
          <node concept="16N2To" id="WfF1I4iY5P" role="4R9Ej">
            <ref role="16N2Tp" node="WfF1I4iXR0" resolve="emergencyAlarm" />
          </node>
        </node>
      </node>
      <node concept="3fbQ3u" id="WfF1I4jrLS" role="3fbPAY">
        <property role="2DRQuN" value="1669905667938" />
        <property role="2DXwbs" value="rijo" />
        <property role="1ylvJX" value="Scenario Emergency Set" />
        <property role="TrG5h" value="emergencySet" />
        <node concept="GmGrk" id="WfF1I4jrLT" role="GmGcz">
          <node concept="1_0LV8" id="WfF1I4jrLU" role="1_0VJ0">
            <node concept="19SGf9" id="WfF1I4jrLV" role="1_0LWR">
              <node concept="19SUe$" id="WfF1I4jrLW" role="19SJt6">
                <property role="19SUeA" value="Scenario for the Use Case described above." />
              </node>
            </node>
          </node>
        </node>
        <node concept="16NtEM" id="WfF1I4jrLX" role="22Mr8z" />
        <node concept="16N2Tr" id="WfF1I4jrLY" role="3faCKd">
          <property role="TrG5h" value="emergencySet" />
          <node concept="16N2TF" id="WfF1I4jrLZ" role="16N2SG">
            <ref role="16N2TC" node="WfF1I4h9S5" resolve="User" />
            <node concept="16Nu5w" id="WfF1I4jrM0" role="16Nr0r">
              <ref role="16Np4H" node="WfF1I4h9XD" resolve="setEmergency" />
              <node concept="16N2To" id="WfF1I4jrM1" role="16NoOW">
                <ref role="16N2Tp" node="WfF1I4h9XC" resolve="emergencyButton" />
              </node>
            </node>
          </node>
          <node concept="16N2TF" id="WfF1I4jrM2" role="16N2SG">
            <ref role="16N2TC" node="WfF1I4h9T1" resolve="liftControl" />
            <node concept="16Mycm" id="WfF1I4jrM3" role="16Nr0r">
              <ref role="16Np4H" node="WfF1I4js0K" resolve="receiveEmergencyTrigger" />
            </node>
            <node concept="16Nu5w" id="WfF1I4jrYX" role="16Nr0r">
              <ref role="16Np4H" node="WfF1I4jrYn" resolve="off" />
              <node concept="16N2To" id="WfF1I4jrYZ" role="16NoOW">
                <ref role="16N2Tp" node="WfF1I4ivZ6" resolve="motorUp" />
              </node>
            </node>
            <node concept="16Nu5w" id="WfF1I4jrZ9" role="16Nr0r">
              <ref role="16Np4H" node="WfF1I4jrYy" resolve="off" />
              <node concept="16N2To" id="WfF1I4jrZb" role="16NoOW">
                <ref role="16N2Tp" node="WfF1I4ivZC" resolve="motorDown" />
              </node>
            </node>
            <node concept="16Nu5w" id="WfF1I4jrZL" role="16Nr0r">
              <ref role="16Np4H" node="WfF1I4jrYP" resolve="on" />
              <node concept="16N2To" id="WfF1I4jrZJ" role="16NoOW">
                <ref role="16N2Tp" node="WfF1I4iXR0" resolve="emergencyAlarm" />
              </node>
            </node>
            <node concept="16Mycm" id="WfF1I4jIpT" role="16Nr0r">
              <ref role="16Np4H" node="WfF1I4js0K" resolve="receiveEmergencyTrigger" />
            </node>
          </node>
          <node concept="16N2TF" id="WfF1I4jrZT" role="16N2SG">
            <ref role="16N2TC" node="WfF1I4haJ_" resolve="safetyTeam" />
            <node concept="16Nu5w" id="WfF1I4jrZZ" role="16Nr0r">
              <ref role="16Np4H" node="WfF1I4jrYQ" resolve="off" />
              <node concept="16N2To" id="WfF1I4js00" role="16NoOW">
                <ref role="16N2Tp" node="WfF1I4iXR0" resolve="emergencyAlarm" />
              </node>
            </node>
            <node concept="16Nu5w" id="WfF1I4jIpw" role="16Nr0r">
              <ref role="16Np4H" node="WfF1I4jIpk" resolve="release" />
              <node concept="16N2To" id="WfF1I4jIpu" role="16NoOW">
                <ref role="16N2Tp" node="WfF1I4h9XC" resolve="emergencyButton" />
              </node>
            </node>
          </node>
        </node>
      </node>
    </node>
    <node concept="3fbQ3u" id="WfF1I4jrvL" role="3fbPIo">
      <property role="2DRQuN" value="1669905667938" />
      <property role="2DXwbs" value="rijo" />
      <property role="1ylvJX" value="Use Case Weight Control System" />
      <property role="TrG5h" value="weightControl" />
      <node concept="GmGrk" id="WfF1I4jrvM" role="GmGcz">
        <node concept="1_0LV8" id="WfF1I4jrvN" role="1_0VJ0">
          <node concept="19SGf9" id="WfF1I4jrvO" role="1_0LWR">
            <node concept="19SUe$" id="WfF1I4jrvP" role="19SJt6">
              <property role="19SUeA" value="Use case where the " />
            </node>
            <node concept="2oIDSw" id="WfF1I4jrvQ" role="19SJt6">
              <ref role="2wPqOu" node="WfF1I4h9RR" resolve="User" />
            </node>
            <node concept="19SUe$" id="WfF1I4jrvR" role="19SJt6">
              <property role="19SUeA" value=" enters the Lift with an object too heavy. The " />
            </node>
            <node concept="2oIDSw" id="WfF1I4jrvU" role="19SJt6">
              <ref role="2wPqOu" node="WfF1I4ha6n" resolve="weightCell" />
            </node>
            <node concept="19SUe$" id="WfF1I4jrvV" role="19SJt6">
              <property role="19SUeA" value=" will activate the " />
            </node>
            <node concept="2oIDSw" id="WfF1I4jrvW" role="19SJt6">
              <ref role="2wPqOu" node="WfF1I4iXz4" resolve="weightAlarm" />
            </node>
            <node concept="19SUe$" id="WfF1I4jrvX" role="19SJt6">
              <property role="19SUeA" value=" and the doors will remain open." />
            </node>
          </node>
        </node>
      </node>
      <node concept="4R1oT" id="WfF1I4jrw4" role="22Mr8z" />
      <node concept="oTeIi" id="WfF1I4jrw5" role="3faCKd" />
      <node concept="4R1oW" id="WfF1I4jrw6" role="3faCKd">
        <property role="TrG5h" value="userEntersWithHeavyObject" />
        <node concept="4RctY" id="WfF1I4jrw7" role="4Rctc">
          <node concept="16N2To" id="WfF1I4jrw8" role="4RctW">
            <ref role="16N2Tp" node="WfF1I4h9S5" resolve="User" />
          </node>
        </node>
        <node concept="4R9Ek" id="WfF1I4jrw9" role="4Rctc">
          <node concept="16N2To" id="WfF1I4jrwa" role="4R9Ej">
            <ref role="16N2Tp" node="WfF1I4ha6t" resolve="weightCell" />
          </node>
        </node>
      </node>
      <node concept="4R1oW" id="WfF1I4jrwb" role="3faCKd">
        <property role="TrG5h" value="weightControl" />
        <node concept="4RctY" id="WfF1I4jrwc" role="4Rctc">
          <node concept="16N2To" id="WfF1I4jrwd" role="4RctW">
            <ref role="16N2Tp" node="WfF1I4ha6t" resolve="weightCell" />
          </node>
        </node>
        <node concept="4R9Ek" id="WfF1I4jrwe" role="4Rctc">
          <node concept="16N2To" id="WfF1I4jrwf" role="4R9Ej">
            <ref role="16N2Tp" node="WfF1I4h9T1" resolve="liftControl" />
          </node>
        </node>
      </node>
      <node concept="4R1oW" id="WfF1I4jrwg" role="3faCKd">
        <property role="TrG5h" value="soundWeightAlarm" />
        <node concept="4RctY" id="WfF1I4jrwh" role="4Rctc">
          <node concept="16N2To" id="WfF1I4jrwi" role="4RctW">
            <ref role="16N2Tp" node="WfF1I4h9T1" resolve="liftControl" />
          </node>
        </node>
        <node concept="4R9Ek" id="WfF1I4jrwj" role="4Rctc">
          <node concept="16N2To" id="WfF1I4jrwk" role="4R9Ej">
            <ref role="16N2Tp" node="WfF1I4iXHN" resolve="weightAlarm" />
          </node>
        </node>
        <node concept="4R9Ek" id="WfF1I4jr$T" role="4Rctc">
          <node concept="16N2To" id="WfF1I4jr$V" role="4R9Ej">
            <ref role="16N2Tp" node="WfF1I4iw4W" resolve="motorOpenDoors" />
          </node>
        </node>
      </node>
      <node concept="3fbQ3u" id="WfF1I4js22" role="3fbPAY">
        <property role="2DRQuN" value="1669905667938" />
        <property role="2DXwbs" value="rijo" />
        <property role="1ylvJX" value="Scenario Max Weight Detected" />
        <property role="TrG5h" value="maxWeightDetected" />
        <node concept="GmGrk" id="WfF1I4js23" role="GmGcz">
          <node concept="1_0LV8" id="WfF1I4js24" role="1_0VJ0">
            <node concept="19SGf9" id="WfF1I4js25" role="1_0LWR">
              <node concept="19SUe$" id="WfF1I4js26" role="19SJt6">
                <property role="19SUeA" value="Scenario for the Use Case described above." />
              </node>
            </node>
          </node>
        </node>
        <node concept="16NtEM" id="WfF1I4js27" role="22Mr8z" />
        <node concept="16N2Tr" id="WfF1I4js28" role="3faCKd">
          <property role="TrG5h" value="maxWeightDetected" />
          <node concept="16N2TF" id="WfF1I4js2c" role="16N2SG">
            <ref role="16N2TC" node="WfF1I4h9T1" resolve="liftControl" />
            <node concept="16Mycm" id="WfF1I4js2d" role="16Nr0r">
              <ref role="16Np4H" node="WfF1I4js1y" resolve="receiveMaxWeightTrigger" />
            </node>
            <node concept="16Nu5w" id="WfF1I4js2e" role="16Nr0r">
              <ref role="16Np4H" node="WfF1I4jrYA" resolve="on" />
              <node concept="16N2To" id="WfF1I4js2f" role="16NoOW">
                <ref role="16N2Tp" node="WfF1I4iw4W" resolve="motorOpenDoors" />
              </node>
            </node>
            <node concept="16Nu5w" id="WfF1I4js2i" role="16Nr0r">
              <ref role="16Np4H" node="WfF1I4jrYK" resolve="on" />
              <node concept="16N2To" id="WfF1I4js2j" role="16NoOW">
                <ref role="16N2Tp" node="WfF1I4iXHN" resolve="weightAlarm" />
              </node>
            </node>
          </node>
        </node>
      </node>
    </node>
    <node concept="3fbQ3u" id="WfF1I4jsaj" role="3fbPIo">
      <property role="2DRQuN" value="1669905667938" />
      <property role="2DXwbs" value="rijo" />
      <property role="1ylvJX" value="Use Case Detection Barrier System" />
      <property role="TrG5h" value="detectionBarrierDetection" />
      <node concept="GmGrk" id="WfF1I4jsak" role="GmGcz">
        <node concept="1_0LV8" id="WfF1I4jsal" role="1_0VJ0">
          <node concept="19SGf9" id="WfF1I4jsam" role="1_0LWR">
            <node concept="19SUe$" id="WfF1I4jsan" role="19SJt6">
              <property role="19SUeA" value="Use case where the " />
            </node>
            <node concept="2oIDSw" id="WfF1I4jsao" role="19SJt6">
              <ref role="2wPqOu" node="WfF1I4h9RR" resolve="User" />
            </node>
            <node concept="19SUe$" id="WfF1I4jsap" role="19SJt6">
              <property role="19SUeA" value=" passes trought the doors when they are closing, .The " />
            </node>
            <node concept="2oIDSw" id="WfF1I4jsaq" role="19SJt6">
              <ref role="2wPqOu" node="WfF1I4jsaj" resolve="detectionBarrier" />
            </node>
            <node concept="19SUe$" id="WfF1I4jsfU" role="19SJt6">
              <property role="19SUeA" value=" will open the doors again." />
            </node>
          </node>
        </node>
      </node>
      <node concept="4R1oT" id="WfF1I4jsau" role="22Mr8z" />
      <node concept="oTeIi" id="WfF1I4jsav" role="3faCKd" />
      <node concept="4R1oW" id="WfF1I4jsaw" role="3faCKd">
        <property role="TrG5h" value="triggerDetection" />
        <node concept="4RctY" id="WfF1I4jsax" role="4Rctc">
          <node concept="16N2To" id="WfF1I4jsay" role="4RctW">
            <ref role="16N2Tp" node="WfF1I4h9S5" resolve="User" />
          </node>
        </node>
        <node concept="4R9Ek" id="WfF1I4jsaz" role="4Rctc">
          <node concept="16N2To" id="WfF1I4jsa$" role="4R9Ej">
            <ref role="16N2Tp" node="WfF1I4ha5l" resolve="detectionBarrier" />
          </node>
        </node>
      </node>
      <node concept="4R1oW" id="WfF1I4jsa_" role="3faCKd">
        <property role="TrG5h" value="detectionBarrierTriggered" />
        <node concept="4RctY" id="WfF1I4jsaA" role="4Rctc">
          <node concept="16N2To" id="WfF1I4jsaB" role="4RctW">
            <ref role="16N2Tp" node="WfF1I4ha5l" resolve="detectionBarrier" />
          </node>
        </node>
        <node concept="4R9Ek" id="WfF1I4jsaC" role="4Rctc">
          <node concept="16N2To" id="WfF1I4jsaD" role="4R9Ej">
            <ref role="16N2Tp" node="WfF1I4h9T1" resolve="liftControl" />
          </node>
        </node>
      </node>
      <node concept="4R1oW" id="WfF1I4jsaE" role="3faCKd">
        <property role="TrG5h" value="openDoors" />
        <node concept="4RctY" id="WfF1I4jsaF" role="4Rctc">
          <node concept="16N2To" id="WfF1I4jsaG" role="4RctW">
            <ref role="16N2Tp" node="WfF1I4h9T1" resolve="liftControl" />
          </node>
        </node>
        <node concept="4R9Ek" id="WfF1I4jsaJ" role="4Rctc">
          <node concept="16N2To" id="WfF1I4jsaK" role="4R9Ej">
            <ref role="16N2Tp" node="WfF1I4iw4W" resolve="motorOpenDoors" />
          </node>
        </node>
      </node>
      <node concept="3fbQ3u" id="WfF1I4jsaL" role="3fbPAY">
        <property role="2DRQuN" value="1669905667938" />
        <property role="2DXwbs" value="rijo" />
        <property role="1ylvJX" value="Scenario Detection Barrier Detection" />
        <property role="TrG5h" value="detectionBarrierTrigger" />
        <node concept="GmGrk" id="WfF1I4jsaM" role="GmGcz">
          <node concept="1_0LV8" id="WfF1I4jsaN" role="1_0VJ0">
            <node concept="19SGf9" id="WfF1I4jsaO" role="1_0LWR">
              <node concept="19SUe$" id="WfF1I4jsaP" role="19SJt6">
                <property role="19SUeA" value="Scenario for the Use Case described above." />
              </node>
            </node>
          </node>
        </node>
        <node concept="16NtEM" id="WfF1I4jsaQ" role="22Mr8z" />
        <node concept="16N2Tr" id="WfF1I4jsaR" role="3faCKd">
          <property role="TrG5h" value="detectionBarrierTrigger" />
          <node concept="16N2TF" id="WfF1I4jsaS" role="16N2SG">
            <ref role="16N2TC" node="WfF1I4h9T1" resolve="liftControl" />
            <node concept="16Mycm" id="WfF1I4jsaT" role="16Nr0r">
              <ref role="16Np4H" node="WfF1I4jsgp" resolve="receiveDetectionBarrierTrigger" />
            </node>
            <node concept="16Nu5w" id="WfF1I4jsaU" role="16Nr0r">
              <ref role="16Np4H" node="WfF1I4jrYA" resolve="on" />
              <node concept="16N2To" id="WfF1I4jsaV" role="16NoOW">
                <ref role="16N2Tp" node="WfF1I4iw4W" resolve="motorOpenDoors" />
              </node>
            </node>
          </node>
        </node>
      </node>
    </node>
  </node>
</model>

