<?xml version="1.0" encoding="UTF-8"?>
<model ref="r:384b171f-9f99-4bec-9bb3-eff2f4cff2fd(office_control.requirements)">
  <persistence version="9" />
  <languages>
    <use id="564e97d6-8fb7-41f5-bfc1-c7ed376efd62" name="com.mbeddr.ext.statemachines" version="1" />
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
      <concept id="5744000828452822758" name="com.mbeddr.cc.requirements.scenarios.structure.ComponentRequirementKind" flags="ng" index="16N1iO" />
      <concept id="5744000828452824074" name="com.mbeddr.cc.requirements.scenarios.structure.ParticipantRef" flags="ng" index="16N2To">
        <reference id="5744000828452824075" name="participant" index="16N2Tp" />
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
  <node concept="3fbPIq" id="3yuK3TkZPU$">
    <property role="TrG5h" value="Requirements" />
    <ref role="G9hjw" node="3yuK3TkZPUD" resolve="DefaultDocConfig" />
    <node concept="3fbQ3u" id="3yuK3TkZT8c" role="3fbPIo">
      <property role="2DRQuN" value="1672915915156" />
      <property role="2DXwbs" value="rijo" />
      <property role="1ylvJX" value="Operational Requirements" />
      <property role="TrG5h" value="operationalReq" />
      <node concept="GmGrk" id="3yuK3TkZT8e" role="GmGcz">
        <node concept="1_0LV8" id="3yuK3TkZT8f" role="1_0VJ0">
          <node concept="19SGf9" id="3yuK3TkZT8g" role="1_0LWR">
            <node concept="19SUe$" id="3yuK3TkZT9b" role="19SJt6">
              <property role="19SUeA" value="The system shall manage the ambient light and temperature inside the office by controlling the lights, blinds and heater." />
            </node>
          </node>
        </node>
      </node>
      <node concept="22Mrfp" id="3yuK3TkZT8i" role="22Mr8z" />
      <node concept="3fbQ3u" id="3yuK3TkZTh7" role="3fbPAY">
        <property role="2DRQuN" value="1672927571085" />
        <property role="2DXwbs" value="rijo" />
        <property role="1ylvJX" value="Sensors Requirements" />
        <property role="TrG5h" value="sensorReq" />
        <node concept="GmGrk" id="3yuK3TkZTh8" role="GmGcz">
          <node concept="1_0LV8" id="3yuK3TkZTh9" role="1_0VJ0">
            <node concept="19SGf9" id="3yuK3TkZTha" role="1_0LWR">
              <node concept="19SUe$" id="3yuK3TkZThb" role="19SJt6">
                <property role="19SUeA" value="The system shall be equiped with sensors to monitor the ambient light and temperature." />
              </node>
            </node>
          </node>
        </node>
        <node concept="22Mrfp" id="3yuK3TkZThc" role="22Mr8z" />
        <node concept="3fbQ3u" id="3yuK3TkZThd" role="3fbPAY">
          <property role="2DRQuN" value="1672927752277" />
          <property role="2DXwbs" value="rijo" />
          <property role="TrG5h" value="sensorComReq" />
          <property role="1ylvJX" value="Sensor Communication Requirements" />
          <node concept="GmGrk" id="3yuK3TkZThe" role="GmGcz">
            <node concept="1_0LV8" id="3yuK3TkZThf" role="1_0VJ0">
              <node concept="19SGf9" id="3yuK3TkZThg" role="1_0LWR">
                <node concept="19SUe$" id="3yuK3TkZThh" role="19SJt6">
                  <property role="19SUeA" value="The sensors shall communicate wirelessly to a control unit " />
                </node>
                <node concept="2oIDSw" id="3yuK3TkZW_W" role="19SJt6">
                  <ref role="2wPqOu" node="3yuK3TkZVy5" resolve="controlUnit" />
                </node>
                <node concept="19SUe$" id="3yuK3TkZW_X" role="19SJt6">
                  <property role="19SUeA" value="." />
                </node>
              </node>
            </node>
          </node>
          <node concept="22Mrfp" id="3yuK3TkZThi" role="22Mr8z" />
        </node>
        <node concept="3fbQ3u" id="3yuK3TkZThj" role="3fbPAY">
          <property role="2DRQuN" value="1672927752277" />
          <property role="2DXwbs" value="rijo" />
          <property role="TrG5h" value="sensorRedundacyReq" />
          <property role="1ylvJX" value="Sensor Redundacy Requirements" />
          <node concept="GmGrk" id="3yuK3TkZThk" role="GmGcz">
            <node concept="1_0LV8" id="3yuK3TkZThl" role="1_0VJ0">
              <node concept="19SGf9" id="3yuK3TkZThm" role="1_0LWR">
                <node concept="19SUe$" id="3yuK3TkZThn" role="19SJt6">
                  <property role="19SUeA" value="The sensors shall have redundacy." />
                </node>
              </node>
            </node>
          </node>
          <node concept="22Mrfp" id="3yuK3TkZTho" role="22Mr8z" />
          <node concept="3fbQ3u" id="3yuK3TkZTCz" role="3fbPAY">
            <property role="2DRQuN" value="1672927752277" />
            <property role="2DXwbs" value="rijo" />
            <property role="TrG5h" value="ambientLightRedundacyReq" />
            <property role="1ylvJX" value="Ambient Light Sensor Redundacy Requirements" />
            <node concept="GmGrk" id="3yuK3TkZTC$" role="GmGcz">
              <node concept="1_0LV8" id="3yuK3TkZTC_" role="1_0VJ0">
                <node concept="19SGf9" id="3yuK3TkZTCA" role="1_0LWR">
                  <node concept="19SUe$" id="3yuK3TkZTCB" role="19SJt6">
                    <property role="19SUeA" value="The ambient light sensors " />
                  </node>
                  <node concept="2oIDSw" id="3yuK3TkZW_Q" role="19SJt6">
                    <ref role="2wPqOu" node="3yuK3TkZVLg" resolve="amblightSensor" />
                  </node>
                  <node concept="19SUe$" id="3yuK3TkZW_R" role="19SJt6">
                    <property role="19SUeA" value=" shall have, at least, two sensors inside the office and two sensors outside the office." />
                  </node>
                </node>
              </node>
            </node>
            <node concept="22Mrfp" id="3yuK3TkZTCC" role="22Mr8z" />
          </node>
          <node concept="3fbQ3u" id="3yuK3TkZTDv" role="3fbPAY">
            <property role="2DRQuN" value="1672927752277" />
            <property role="2DXwbs" value="rijo" />
            <property role="TrG5h" value="temperatureRedundacyReq" />
            <property role="1ylvJX" value="Temperature Sensor Redundacy Requirements" />
            <node concept="GmGrk" id="3yuK3TkZTDw" role="GmGcz">
              <node concept="1_0LV8" id="3yuK3TkZTDx" role="1_0VJ0">
                <node concept="19SGf9" id="3yuK3TkZTDy" role="1_0LWR">
                  <node concept="19SUe$" id="3yuK3TkZTDz" role="19SJt6">
                    <property role="19SUeA" value="The temperature sensors " />
                  </node>
                  <node concept="2oIDSw" id="3yuK3TkZW_K" role="19SJt6">
                    <ref role="2wPqOu" node="3yuK3TkZVI0" resolve="tempSensor" />
                  </node>
                  <node concept="19SUe$" id="3yuK3TkZW_L" role="19SJt6">
                    <property role="19SUeA" value=" shall have, at least, two sensors inside the office." />
                  </node>
                </node>
              </node>
            </node>
            <node concept="22Mrfp" id="3yuK3TkZTD$" role="22Mr8z" />
          </node>
        </node>
        <node concept="3fbQ3u" id="3yuK3TkZTLB" role="3fbPAY">
          <property role="2DRQuN" value="1672927752277" />
          <property role="2DXwbs" value="rijo" />
          <property role="TrG5h" value="sensorMsgReq" />
          <property role="1ylvJX" value="Sensor Message Requirements" />
          <node concept="GmGrk" id="3yuK3TkZTLC" role="GmGcz">
            <node concept="1_0LV8" id="3yuK3TkZTLD" role="1_0VJ0">
              <node concept="19SGf9" id="3yuK3TkZTLE" role="1_0LWR">
                <node concept="19SUe$" id="3yuK3TkZTLF" role="19SJt6">
                  <property role="19SUeA" value="When the sensors are connected, they shall send to the control unit " />
                </node>
                <node concept="2oIDSw" id="3yuK3TkZW_E" role="19SJt6">
                  <ref role="2wPqOu" node="3yuK3TkZVy5" resolve="controlUnit" />
                </node>
                <node concept="19SUe$" id="3yuK3TkZW_F" role="19SJt6">
                  <property role="19SUeA" value=" an error message" />
                </node>
              </node>
            </node>
          </node>
          <node concept="22Mrfp" id="3yuK3TkZTLG" role="22Mr8z" />
          <node concept="3fbQ3u" id="53MU4peyaAm" role="3fbPAY">
            <property role="2DRQuN" value="1672927752277" />
            <property role="2DXwbs" value="rijo" />
            <property role="TrG5h" value="errorSensorMsgReq" />
            <property role="1ylvJX" value="Sensor Message Requirements" />
            <node concept="GmGrk" id="53MU4peyaAn" role="GmGcz">
              <node concept="1_0LV8" id="53MU4peyaAo" role="1_0VJ0">
                <node concept="19SGf9" id="53MU4peyaAp" role="1_0LWR">
                  <node concept="19SUe$" id="53MU4peyaAq" role="19SJt6">
                    <property role="19SUeA" value="The error message shal be composed by: office ID, sensor type, average of readings and error code." />
                  </node>
                </node>
              </node>
            </node>
            <node concept="22Mrfp" id="53MU4peyaAt" role="22Mr8z" />
          </node>
        </node>
      </node>
      <node concept="3fbQ3u" id="3yuK3TkZTk3" role="3fbPAY">
        <property role="2DRQuN" value="1672927752277" />
        <property role="2DXwbs" value="rijo" />
        <property role="1ylvJX" value="Parameters Requirements" />
        <property role="TrG5h" value="paramReq" />
        <node concept="GmGrk" id="3yuK3TkZTk4" role="GmGcz">
          <node concept="1_0LV8" id="3yuK3TkZTk5" role="1_0VJ0">
            <node concept="19SGf9" id="3yuK3TkZTk6" role="1_0LWR">
              <node concept="19SUe$" id="3yuK3TkZTk7" role="19SJt6">
                <property role="19SUeA" value="The system shall have a determined range of max values and set points" />
              </node>
            </node>
          </node>
        </node>
        <node concept="22Mrfp" id="3yuK3TkZTk8" role="22Mr8z" />
        <node concept="3fbQ3u" id="53MU4peyaC3" role="3fbPAY">
          <property role="2DRQuN" value="1672927752277" />
          <property role="2DXwbs" value="rijo" />
          <property role="1ylvJX" value="Parameters Requirements" />
          <property role="TrG5h" value="param2Req" />
          <node concept="GmGrk" id="53MU4peyaC4" role="GmGcz">
            <node concept="1_0LV8" id="53MU4peyaC5" role="1_0VJ0">
              <node concept="19SGf9" id="53MU4peyaC6" role="1_0LWR">
                <node concept="19SUe$" id="53MU4peyaC7" role="19SJt6">
                  <property role="19SUeA" value="The system parameters shall be: " />
                </node>
                <node concept="2oIDSw" id="53MU4peyaC8" role="19SJt6">
                  <ref role="2wPqOu" node="3yuK3TkZWDv" resolve="tempMaxValue" />
                </node>
                <node concept="19SUe$" id="53MU4peyaC9" role="19SJt6">
                  <property role="19SUeA" value=", " />
                </node>
                <node concept="2oIDSw" id="53MU4peyaCa" role="19SJt6">
                  <ref role="2wPqOu" node="3yuK3TkZWDL" resolve="tempMinValue" />
                </node>
                <node concept="19SUe$" id="53MU4peyaCb" role="19SJt6">
                  <property role="19SUeA" value=", " />
                </node>
                <node concept="2oIDSw" id="53MU4peyaCc" role="19SJt6">
                  <ref role="2wPqOu" node="3yuK3TkZWEB" resolve="amblightMaxValue" />
                </node>
                <node concept="19SUe$" id="53MU4peyaCd" role="19SJt6">
                  <property role="19SUeA" value=", " />
                </node>
                <node concept="2oIDSw" id="53MU4peyaCe" role="19SJt6">
                  <ref role="2wPqOu" node="3yuK3TkZWEH" resolve="amblightMinValue" />
                </node>
                <node concept="19SUe$" id="53MU4peyaCf" role="19SJt6">
                  <property role="19SUeA" value=", " />
                </node>
                <node concept="2oIDSw" id="53MU4peyaCg" role="19SJt6">
                  <ref role="2wPqOu" node="3yuK3TkZWDj" resolve="tempSetPoint" />
                </node>
                <node concept="19SUe$" id="53MU4peyaCh" role="19SJt6">
                  <property role="19SUeA" value=" and " />
                </node>
                <node concept="2oIDSw" id="53MU4peyaCi" role="19SJt6">
                  <ref role="2wPqOu" node="3yuK3TkZWE9" resolve="amblightSetPoint" />
                </node>
                <node concept="19SUe$" id="53MU4peyaCj" role="19SJt6">
                  <property role="19SUeA" value="." />
                </node>
              </node>
            </node>
          </node>
          <node concept="22Mrfp" id="53MU4peyaCk" role="22Mr8z" />
        </node>
      </node>
      <node concept="3fbQ3u" id="3yuK3TkZTaM" role="3fbPAY">
        <property role="2DRQuN" value="1672927571085" />
        <property role="2DXwbs" value="rijo" />
        <property role="1ylvJX" value="Actuators Requirements" />
        <property role="TrG5h" value="actuatorReq" />
        <node concept="GmGrk" id="3yuK3TkZTaO" role="GmGcz">
          <node concept="1_0LV8" id="3yuK3TkZTaP" role="1_0VJ0">
            <node concept="19SGf9" id="3yuK3TkZTaQ" role="1_0LWR">
              <node concept="19SUe$" id="3yuK3TkZTaR" role="19SJt6">
                <property role="19SUeA" value="The system shall be equiped with a set of lights " />
              </node>
              <node concept="2oIDSw" id="3yuK3TkZW_i" role="19SJt6">
                <ref role="2wPqOu" node="3yuK3TkZV$k" resolve="lights" />
              </node>
              <node concept="19SUe$" id="3yuK3TkZW_j" role="19SJt6">
                <property role="19SUeA" value=", a blinds " />
              </node>
              <node concept="2oIDSw" id="3yuK3TkZW_o" role="19SJt6">
                <ref role="2wPqOu" node="3yuK3TkZV$N" resolve="blinds" />
              </node>
              <node concept="19SUe$" id="3yuK3TkZW_p" role="19SJt6">
                <property role="19SUeA" value=" and an heater " />
              </node>
              <node concept="2oIDSw" id="3yuK3TkZW_w" role="19SJt6">
                <ref role="2wPqOu" node="3yuK3TkZVyC" resolve="heater" />
              </node>
              <node concept="19SUe$" id="3yuK3TkZW_x" role="19SJt6">
                <property role="19SUeA" value="." />
              </node>
            </node>
          </node>
        </node>
        <node concept="22Mrfp" id="3yuK3TkZTaS" role="22Mr8z" />
        <node concept="3fbQ3u" id="3yuK3TkZTbJ" role="3fbPAY">
          <property role="2DRQuN" value="1672927752277" />
          <property role="2DXwbs" value="rijo" />
          <property role="1ylvJX" value="Actuators Communication Requirements" />
          <property role="TrG5h" value="actuatorComReq" />
          <node concept="GmGrk" id="3yuK3TkZTbL" role="GmGcz">
            <node concept="1_0LV8" id="3yuK3TkZTbM" role="1_0VJ0">
              <node concept="19SGf9" id="3yuK3TkZTbN" role="1_0LWR">
                <node concept="19SUe$" id="3yuK3TkZTbO" role="19SJt6">
                  <property role="19SUeA" value="The actuators shall communicate wirelessly to a control unit " />
                </node>
                <node concept="2oIDSw" id="3yuK3TkZW_c" role="19SJt6">
                  <ref role="2wPqOu" node="3yuK3TkZVy5" resolve="controlUnit" />
                </node>
                <node concept="19SUe$" id="3yuK3TkZW_d" role="19SJt6">
                  <property role="19SUeA" value="." />
                </node>
              </node>
            </node>
          </node>
          <node concept="22Mrfp" id="3yuK3TkZTbP" role="22Mr8z" />
        </node>
        <node concept="3fbQ3u" id="3yuK3TkZTj$" role="3fbPAY">
          <property role="2DRQuN" value="1672927752277" />
          <property role="2DXwbs" value="rijo" />
          <property role="1ylvJX" value="Actuators Timeout Requirements" />
          <property role="TrG5h" value="actuatorTimeoutReq" />
          <node concept="GmGrk" id="3yuK3TkZTj_" role="GmGcz">
            <node concept="1_0LV8" id="3yuK3TkZTjA" role="1_0VJ0">
              <node concept="19SGf9" id="3yuK3TkZTjB" role="1_0LWR">
                <node concept="19SUe$" id="3yuK3TkZTjC" role="19SJt6">
                  <property role="19SUeA" value="The actuators shall have an expected time (" />
                </node>
                <node concept="2oIDSw" id="3yuK3TkZWNc" role="19SJt6">
                  <ref role="2wPqOu" node="3yuK3TkZWKu" resolve="actTimeoutValue" />
                </node>
                <node concept="19SUe$" id="3yuK3TkZWNd" role="19SJt6">
                  <property role="19SUeA" value=") to reach the target value/positon" />
                </node>
              </node>
            </node>
          </node>
          <node concept="22Mrfp" id="3yuK3TkZTjD" role="22Mr8z" />
        </node>
      </node>
      <node concept="3fbQ3u" id="3yuK3TkZTlD" role="3fbPAY">
        <property role="2DRQuN" value="1672927752277" />
        <property role="2DXwbs" value="rijo" />
        <property role="1ylvJX" value="User Detection Requirements" />
        <property role="TrG5h" value="userReq" />
        <node concept="GmGrk" id="3yuK3TkZTlE" role="GmGcz">
          <node concept="1_0LV8" id="3yuK3TkZTlF" role="1_0VJ0">
            <node concept="19SGf9" id="3yuK3TkZTlG" role="1_0LWR">
              <node concept="19SUe$" id="3yuK3TkZTlH" role="19SJt6">
                <property role="19SUeA" value="The system shall have the capability to know if the " />
              </node>
              <node concept="2oIDSw" id="3yuK3TkZW$O" role="19SJt6">
                <ref role="2wPqOu" node="3yuK3TkZTrD" resolve="user" />
              </node>
              <node concept="19SUe$" id="3yuK3TkZW$P" role="19SJt6">
                <property role="19SUeA" value=" is in the office." />
              </node>
            </node>
          </node>
        </node>
        <node concept="22Mrfp" id="3yuK3TkZTlI" role="22Mr8z" />
      </node>
      <node concept="3fbQ3u" id="3yuK3TkZTnl" role="3fbPAY">
        <property role="2DRQuN" value="1672927752277" />
        <property role="2DXwbs" value="rijo" />
        <property role="1ylvJX" value="Control Unit Requirements" />
        <property role="TrG5h" value="controllerReq" />
        <node concept="GmGrk" id="3yuK3TkZTnm" role="GmGcz">
          <node concept="1_0LV8" id="3yuK3TkZTnn" role="1_0VJ0">
            <node concept="19SGf9" id="3yuK3TkZTno" role="1_0LWR">
              <node concept="19SUe$" id="3yuK3TkZTnp" role="19SJt6">
                <property role="19SUeA" value="The system shall have a control unit " />
              </node>
              <node concept="2oIDSw" id="3yuK3TkZW$J" role="19SJt6">
                <ref role="2wPqOu" node="3yuK3TkZVy5" resolve="controlUnit" />
              </node>
              <node concept="19SUe$" id="3yuK3TkZW$K" role="19SJt6">
                <property role="19SUeA" value=" to control the enviroment of the office" />
              </node>
            </node>
          </node>
        </node>
        <node concept="22Mrfp" id="3yuK3TkZTnq" role="22Mr8z" />
        <node concept="3fbQ3u" id="3yuK3TkZTot" role="3fbPAY">
          <property role="2DRQuN" value="1672927752277" />
          <property role="2DXwbs" value="rijo" />
          <property role="1ylvJX" value="Control Unit Communication Requirements" />
          <property role="TrG5h" value="controllerComReq" />
          <node concept="GmGrk" id="3yuK3TkZTou" role="GmGcz">
            <node concept="1_0LV8" id="3yuK3TkZTov" role="1_0VJ0">
              <node concept="19SGf9" id="3yuK3TkZTow" role="1_0LWR">
                <node concept="19SUe$" id="3yuK3TkZTox" role="19SJt6">
                  <property role="19SUeA" value="The control unit " />
                </node>
                <node concept="2oIDSw" id="3yuK3TkZW$D" role="19SJt6">
                  <ref role="2wPqOu" node="3yuK3TkZVy5" resolve="controlUnit" />
                </node>
                <node concept="19SUe$" id="3yuK3TkZW$E" role="19SJt6">
                  <property role="19SUeA" value=" shall communicate wiressly with the sensors and actuators." />
                </node>
              </node>
            </node>
          </node>
          <node concept="22Mrfp" id="3yuK3TkZToy" role="22Mr8z" />
        </node>
        <node concept="3fbQ3u" id="3yuK3TkZTqT" role="3fbPAY">
          <property role="2DRQuN" value="1672927752277" />
          <property role="2DXwbs" value="rijo" />
          <property role="1ylvJX" value="Control Unit Interface Requirements" />
          <property role="TrG5h" value="controllerHMIReq" />
          <node concept="GmGrk" id="3yuK3TkZTqU" role="GmGcz">
            <node concept="1_0LV8" id="3yuK3TkZTqV" role="1_0VJ0">
              <node concept="19SGf9" id="3yuK3TkZTqW" role="1_0LWR">
                <node concept="19SUe$" id="3yuK3TkZTqX" role="19SJt6">
                  <property role="19SUeA" value="The control unit " />
                </node>
                <node concept="2oIDSw" id="3yuK3TkZW$r" role="19SJt6">
                  <ref role="2wPqOu" node="3yuK3TkZVy5" resolve="controlUnit" />
                </node>
                <node concept="19SUe$" id="3yuK3TkZW$s" role="19SJt6">
                  <property role="19SUeA" value=" shall be equipped with a human-machine interface (" />
                </node>
                <node concept="2oIDSw" id="3yuK3TkZW$x" role="19SJt6">
                  <ref role="2wPqOu" node="3yuK3TkZVDT" resolve="hmi" />
                </node>
                <node concept="19SUe$" id="3yuK3TkZW$y" role="19SJt6">
                  <property role="19SUeA" value=") with the overall status of the office and with buttons to control each actuator manually." />
                </node>
              </node>
            </node>
          </node>
          <node concept="22Mrfp" id="3yuK3TkZTqY" role="22Mr8z" />
        </node>
        <node concept="3fbQ3u" id="3yuK3TkZTre" role="3fbPAY">
          <property role="2DRQuN" value="1672916124661" />
          <property role="2DXwbs" value="rijo" />
          <property role="1ylvJX" value="Control Unit Error Requirements" />
          <property role="TrG5h" value="controllerErrorReq" />
          <node concept="GmGrk" id="3yuK3TkZTrf" role="GmGcz">
            <node concept="1_0LV8" id="3yuK3TkZTrg" role="1_0VJ0">
              <node concept="19SGf9" id="3yuK3TkZTrh" role="1_0LWR">
                <node concept="19SUe$" id="3yuK3TkZTri" role="19SJt6">
                  <property role="19SUeA" value="The control unit " />
                </node>
                <node concept="2oIDSw" id="3yuK3TkZW$j" role="19SJt6">
                  <ref role="2wPqOu" node="3yuK3TkZVy5" resolve="controlUnit" />
                </node>
                <node concept="19SUe$" id="3yuK3TkZW$i" role="19SJt6">
                  <property role="19SUeA" value=" shall receive errors from the sensors and actuators and send (wirelessly) the information to the maintenence department (" />
                </node>
                <node concept="2oIDSw" id="3yuK3TkZWzU" role="19SJt6">
                  <ref role="2wPqOu" node="3yuK3TkZTrY" resolve="maintenanceDep" />
                </node>
                <node concept="19SUe$" id="3yuK3TkZWzT" role="19SJt6">
                  <property role="19SUeA" value=")." />
                </node>
              </node>
            </node>
          </node>
          <node concept="22Mrfp" id="3yuK3TkZTrj" role="22Mr8z" />
        </node>
        <node concept="3fbQ3u" id="3yuK3TkZTQF" role="3fbPAY">
          <property role="2DRQuN" value="1672916124661" />
          <property role="2DXwbs" value="rijo" />
          <property role="1ylvJX" value="Control Unit Log Requirements" />
          <property role="TrG5h" value="controllerLogReq" />
          <node concept="GmGrk" id="3yuK3TkZTQG" role="GmGcz">
            <node concept="1_0LV8" id="3yuK3TkZTQH" role="1_0VJ0">
              <node concept="19SGf9" id="3yuK3TkZTQI" role="1_0LWR">
                <node concept="19SUe$" id="3yuK3TkZTQJ" role="19SJt6">
                  <property role="19SUeA" value="The control unit " />
                </node>
                <node concept="2oIDSw" id="3yuK3TkZW$e" role="19SJt6">
                  <ref role="2wPqOu" node="3yuK3TkZVy5" resolve="controlUnit" />
                </node>
                <node concept="19SUe$" id="3yuK3TkZW$d" role="19SJt6">
                  <property role="19SUeA" value=" shall log each event of the system" />
                </node>
              </node>
            </node>
          </node>
          <node concept="22Mrfp" id="3yuK3TkZTQM" role="22Mr8z" />
        </node>
      </node>
      <node concept="3fbQ3u" id="3yuK3TkZTJZ" role="3fbPAY">
        <property role="2DRQuN" value="1672927752277" />
        <property role="2DXwbs" value="rijo" />
        <property role="1ylvJX" value="Maitenence Department Control Requirements" />
        <property role="TrG5h" value="maintenanceDepControlReq" />
        <node concept="GmGrk" id="3yuK3TkZTK0" role="GmGcz">
          <node concept="1_0LV8" id="3yuK3TkZTK1" role="1_0VJ0">
            <node concept="19SGf9" id="3yuK3TkZTK2" role="1_0LWR">
              <node concept="19SUe$" id="3yuK3TkZTK3" role="19SJt6">
                <property role="19SUeA" value="The Maintenance department " />
              </node>
              <node concept="2oIDSw" id="3yuK3TkZW$8" role="19SJt6">
                <ref role="2wPqOu" node="3yuK3TkZTrY" resolve="maintenanceDep" />
              </node>
              <node concept="19SUe$" id="3yuK3TkZW$9" role="19SJt6">
                <property role="19SUeA" value=" shall always be able to override and block the settings defined in each office." />
              </node>
            </node>
          </node>
        </node>
        <node concept="22Mrfp" id="3yuK3TkZTK4" role="22Mr8z" />
        <node concept="3fbQ3u" id="3yuK3TkZTNd" role="3fbPAY">
          <property role="2DRQuN" value="1672927752277" />
          <property role="2DXwbs" value="rijo" />
          <property role="1ylvJX" value="Maitenence Department Interface Requirements" />
          <property role="TrG5h" value="maintenanceDepHMIReq" />
          <node concept="GmGrk" id="3yuK3TkZTNe" role="GmGcz">
            <node concept="1_0LV8" id="3yuK3TkZTNf" role="1_0VJ0">
              <node concept="19SGf9" id="3yuK3TkZTNg" role="1_0LWR">
                <node concept="19SUe$" id="3yuK3TkZTNh" role="19SJt6">
                  <property role="19SUeA" value="The maintenance department " />
                </node>
                <node concept="2oIDSw" id="3yuK3TkZWzO" role="19SJt6">
                  <ref role="2wPqOu" node="3yuK3TkZTrY" resolve="maintenanceDep" />
                </node>
                <node concept="19SUe$" id="3yuK3TkZWzP" role="19SJt6">
                  <property role="19SUeA" value=" shall be equipped with a user interface (" />
                </node>
                <node concept="2oIDSw" id="3yuK3TkZW$1" role="19SJt6">
                  <ref role="2wPqOu" node="3yuK3TkZW3f" resolve="ui" />
                </node>
                <node concept="19SUe$" id="3yuK3TkZW$2" role="19SJt6">
                  <property role="19SUeA" value=") with the overall status of each office." />
                </node>
              </node>
            </node>
          </node>
          <node concept="22Mrfp" id="3yuK3TkZTNi" role="22Mr8z" />
        </node>
      </node>
    </node>
    <node concept="3fbQ3u" id="3yuK3TkZT9l" role="3fbPIo">
      <property role="2DRQuN" value="1672916124661" />
      <property role="2DXwbs" value="rijo" />
      <property role="1ylvJX" value="Behaviour Requirements" />
      <property role="TrG5h" value="behaviourReq" />
      <node concept="GmGrk" id="3yuK3TkZT9n" role="GmGcz">
        <node concept="1_0LV8" id="3yuK3TkZT9o" role="1_0VJ0">
          <node concept="19SGf9" id="3yuK3TkZT9p" role="1_0LWR">
            <node concept="19SUe$" id="3yuK3TkZT9q" role="19SJt6">
              <property role="19SUeA" value="The system shall behave according to " />
            </node>
            <node concept="2oIDSw" id="3yuK3TkZTSk" role="19SJt6">
              <ref role="2wPqOu" node="3yuK3TkZT8c" resolve="operationalReq" />
            </node>
            <node concept="19SUe$" id="3yuK3TkZTSl" role="19SJt6" />
          </node>
        </node>
      </node>
      <node concept="22Mrfp" id="3yuK3TkZT9r" role="22Mr8z" />
      <node concept="3fbQ3u" id="3yuK3TkZTyB" role="3fbPAY">
        <property role="2DRQuN" value="1672916124661" />
        <property role="2DXwbs" value="rijo" />
        <property role="1ylvJX" value="Blinds Behaviour Requirements" />
        <property role="TrG5h" value="blindsBehaviourReq" />
        <node concept="GmGrk" id="3yuK3TkZTyC" role="GmGcz">
          <node concept="1_0LV8" id="3yuK3TkZTyD" role="1_0VJ0">
            <node concept="19SGf9" id="3yuK3TkZTyE" role="1_0LWR">
              <node concept="19SUe$" id="3yuK3TkZTyF" role="19SJt6">
                <property role="19SUeA" value="The blinds " />
              </node>
              <node concept="2oIDSw" id="3yuK3TkZWzJ" role="19SJt6">
                <ref role="2wPqOu" node="3yuK3TkZV$N" resolve="blinds" />
              </node>
              <node concept="19SUe$" id="3yuK3TkZWzK" role="19SJt6">
                <property role="19SUeA" value=" shall adjust according to the office ambient light defined set point." />
              </node>
            </node>
          </node>
        </node>
        <node concept="22Mrfp" id="3yuK3TkZTyG" role="22Mr8z" />
        <node concept="3fbQ3u" id="3yuK3TkZTAD" role="3fbPAY">
          <property role="2DRQuN" value="1672916124661" />
          <property role="2DXwbs" value="rijo" />
          <property role="1ylvJX" value="Blinds Behaviour Requirements" />
          <property role="TrG5h" value="blindsMovementReq" />
          <node concept="GmGrk" id="3yuK3TkZTAE" role="GmGcz">
            <node concept="1_0LV8" id="3yuK3TkZTAF" role="1_0VJ0">
              <node concept="19SGf9" id="3yuK3TkZTAG" role="1_0LWR">
                <node concept="19SUe$" id="3yuK3TkZTAH" role="19SJt6">
                  <property role="19SUeA" value="The blinds " />
                </node>
                <node concept="2oIDSw" id="3yuK3TkZWzg" role="19SJt6">
                  <ref role="2wPqOu" node="3yuK3TkZV$N" resolve="blinds" />
                </node>
                <node concept="19SUe$" id="3yuK3TkZWzh" role="19SJt6">
                  <property role="19SUeA" value=" shall move in intervals of 25%." />
                </node>
              </node>
            </node>
          </node>
          <node concept="22Mrfp" id="3yuK3TkZTAI" role="22Mr8z" />
        </node>
        <node concept="3fbQ3u" id="3yuK3TkZTBd" role="3fbPAY">
          <property role="2DRQuN" value="1672916124661" />
          <property role="2DXwbs" value="rijo" />
          <property role="1ylvJX" value="Blinds Behaviour Requirements" />
          <property role="TrG5h" value="blindsMovementLimitReq" />
          <node concept="GmGrk" id="3yuK3TkZTBe" role="GmGcz">
            <node concept="1_0LV8" id="3yuK3TkZTBf" role="1_0VJ0">
              <node concept="19SGf9" id="3yuK3TkZTBg" role="1_0LWR">
                <node concept="19SUe$" id="3yuK3TkZTBh" role="19SJt6">
                  <property role="19SUeA" value="The blinds " />
                </node>
                <node concept="2oIDSw" id="3yuK3TkZWzm" role="19SJt6">
                  <ref role="2wPqOu" node="3yuK3TkZV$N" resolve="blinds" />
                </node>
                <node concept="19SUe$" id="3yuK3TkZWzl" role="19SJt6">
                  <property role="19SUeA" value=" shall have sensors " />
                </node>
                <node concept="2oIDSw" id="3yuK3TkZWzb" role="19SJt6">
                  <ref role="2wPqOu" node="3yuK3TkZVUI" resolve="blindsPosition" />
                </node>
                <node concept="19SUe$" id="3yuK3TkZWzc" role="19SJt6">
                  <property role="19SUeA" value=" to detect when the blind is in the desired position" />
                </node>
              </node>
            </node>
          </node>
          <node concept="22Mrfp" id="3yuK3TkZTBi" role="22Mr8z" />
        </node>
        <node concept="3fbQ3u" id="3yuK3TkZTBv" role="3fbPAY">
          <property role="2DRQuN" value="1672916124661" />
          <property role="2DXwbs" value="rijo" />
          <property role="1ylvJX" value="Blinds Behaviour Requirements" />
          <property role="TrG5h" value="blindsControlReq" />
          <node concept="GmGrk" id="3yuK3TkZTBw" role="GmGcz">
            <node concept="1_0LV8" id="3yuK3TkZTBx" role="1_0VJ0">
              <node concept="19SGf9" id="3yuK3TkZTBy" role="1_0LWR">
                <node concept="19SUe$" id="3yuK3TkZTBz" role="19SJt6">
                  <property role="19SUeA" value="The blinds " />
                </node>
                <node concept="2oIDSw" id="3yuK3TkZWzv" role="19SJt6">
                  <ref role="2wPqOu" node="3yuK3TkZV$N" resolve="blinds" />
                </node>
                <node concept="19SUe$" id="3yuK3TkZWzw" role="19SJt6">
                  <property role="19SUeA" value=" shall be able to be controlled autonomously or manually (by the " />
                </node>
                <node concept="2oIDSw" id="3yuK3TkZWyM" role="19SJt6">
                  <ref role="2wPqOu" node="3yuK3TkZTrD" resolve="user" />
                </node>
                <node concept="19SUe$" id="3yuK3TkZWyN" role="19SJt6">
                  <property role="19SUeA" value=" or by the maintenence department " />
                </node>
                <node concept="2oIDSw" id="3yuK3TkZWyO" role="19SJt6">
                  <ref role="2wPqOu" node="3yuK3TkZTrY" resolve="maintenanceDep" />
                </node>
                <node concept="19SUe$" id="3yuK3TkZWyP" role="19SJt6">
                  <property role="19SUeA" value=")." />
                </node>
              </node>
            </node>
          </node>
          <node concept="22Mrfp" id="3yuK3TkZTB$" role="22Mr8z" />
        </node>
      </node>
      <node concept="3fbQ3u" id="3yuK3TkZTDL" role="3fbPAY">
        <property role="2DRQuN" value="1672916124661" />
        <property role="2DXwbs" value="rijo" />
        <property role="1ylvJX" value="Lights Behaviour Requirements" />
        <property role="TrG5h" value="lightsBehaviourReq" />
        <node concept="GmGrk" id="3yuK3TkZTDM" role="GmGcz">
          <node concept="1_0LV8" id="3yuK3TkZTDN" role="1_0VJ0">
            <node concept="19SGf9" id="3yuK3TkZTDO" role="1_0LWR">
              <node concept="19SUe$" id="3yuK3TkZTDP" role="19SJt6">
                <property role="19SUeA" value="The lights " />
              </node>
              <node concept="2oIDSw" id="3yuK3TkZWz5" role="19SJt6">
                <ref role="2wPqOu" node="3yuK3TkZV$k" resolve="lights" />
              </node>
              <node concept="19SUe$" id="3yuK3TkZWz4" role="19SJt6">
                <property role="19SUeA" value=" shall have the capability to adjust its brightness according to the office ambient light defined set point." />
              </node>
            </node>
          </node>
        </node>
        <node concept="22Mrfp" id="3yuK3TkZTDQ" role="22Mr8z" />
        <node concept="3fbQ3u" id="3yuK3TkZTE3" role="3fbPAY">
          <property role="2DRQuN" value="1672916124661" />
          <property role="2DXwbs" value="rijo" />
          <property role="1ylvJX" value="Lights Behaviour Requirements" />
          <property role="TrG5h" value="lightsControlReq" />
          <node concept="GmGrk" id="3yuK3TkZTE4" role="GmGcz">
            <node concept="1_0LV8" id="3yuK3TkZTE5" role="1_0VJ0">
              <node concept="19SGf9" id="3yuK3TkZTE6" role="1_0LWR">
                <node concept="19SUe$" id="3yuK3TkZTE7" role="19SJt6">
                  <property role="19SUeA" value="The lights " />
                </node>
                <node concept="2oIDSw" id="3yuK3TkZWyV" role="19SJt6">
                  <ref role="2wPqOu" node="3yuK3TkZV$k" resolve="lights" />
                </node>
                <node concept="19SUe$" id="3yuK3TkZWyW" role="19SJt6">
                  <property role="19SUeA" value=" shall be able to be controlled autonomously or manually  (by the " />
                </node>
                <node concept="2oIDSw" id="3yuK3TkZWy_" role="19SJt6">
                  <ref role="2wPqOu" node="3yuK3TkZTrD" resolve="user" />
                </node>
                <node concept="19SUe$" id="3yuK3TkZWyA" role="19SJt6">
                  <property role="19SUeA" value=" or by the maintenence department " />
                </node>
                <node concept="2oIDSw" id="3yuK3TkZWyB" role="19SJt6">
                  <ref role="2wPqOu" node="3yuK3TkZTrY" resolve="maintenanceDep" />
                </node>
                <node concept="19SUe$" id="3yuK3TkZWyC" role="19SJt6">
                  <property role="19SUeA" value=")." />
                </node>
              </node>
            </node>
          </node>
          <node concept="22Mrfp" id="3yuK3TkZTE8" role="22Mr8z" />
        </node>
      </node>
      <node concept="3fbQ3u" id="3yuK3TkZTG3" role="3fbPAY">
        <property role="2DRQuN" value="1672916124661" />
        <property role="2DXwbs" value="rijo" />
        <property role="1ylvJX" value="Heater Behaviour Requirements" />
        <property role="TrG5h" value="heaterBehaviourReq" />
        <node concept="GmGrk" id="3yuK3TkZTG4" role="GmGcz">
          <node concept="1_0LV8" id="3yuK3TkZTG5" role="1_0VJ0">
            <node concept="19SGf9" id="3yuK3TkZTG6" role="1_0LWR">
              <node concept="19SUe$" id="3yuK3TkZTG7" role="19SJt6">
                <property role="19SUeA" value="The heater " />
              </node>
              <node concept="2oIDSw" id="3yuK3TkZWyw" role="19SJt6">
                <ref role="2wPqOu" node="3yuK3TkZVyC" resolve="heater" />
              </node>
              <node concept="19SUe$" id="3yuK3TkZWyv" role="19SJt6">
                <property role="19SUeA" value=" shall have the capability to adjust its temperature according to the office temperature defined set point." />
              </node>
            </node>
          </node>
        </node>
        <node concept="22Mrfp" id="3yuK3TkZTG8" role="22Mr8z" />
        <node concept="3fbQ3u" id="3yuK3TkZTGf" role="3fbPAY">
          <property role="2DRQuN" value="1672916124661" />
          <property role="2DXwbs" value="rijo" />
          <property role="1ylvJX" value="Heater Behaviour Requirements" />
          <property role="TrG5h" value="heaterControlReq" />
          <node concept="GmGrk" id="3yuK3TkZTGg" role="GmGcz">
            <node concept="1_0LV8" id="3yuK3TkZTGh" role="1_0VJ0">
              <node concept="19SGf9" id="3yuK3TkZTGi" role="1_0LWR">
                <node concept="19SUe$" id="3yuK3TkZTGj" role="19SJt6">
                  <property role="19SUeA" value="The heater " />
                </node>
                <node concept="2oIDSw" id="3yuK3TkZWym" role="19SJt6">
                  <ref role="2wPqOu" node="3yuK3TkZVyC" resolve="heater" />
                </node>
                <node concept="19SUe$" id="3yuK3TkZWyn" role="19SJt6">
                  <property role="19SUeA" value=" shall be able to be controlled autonomously or manually (by the " />
                </node>
                <node concept="2oIDSw" id="3yuK3TkZWya" role="19SJt6">
                  <ref role="2wPqOu" node="3yuK3TkZTrD" resolve="user" />
                </node>
                <node concept="19SUe$" id="3yuK3TkZWyb" role="19SJt6">
                  <property role="19SUeA" value=" or by the maintenence department " />
                </node>
                <node concept="2oIDSw" id="3yuK3TkZWyf" role="19SJt6">
                  <ref role="2wPqOu" node="3yuK3TkZTrY" resolve="maintenanceDep" />
                </node>
                <node concept="19SUe$" id="3yuK3TkZWyg" role="19SJt6">
                  <property role="19SUeA" value=")." />
                </node>
              </node>
            </node>
          </node>
          <node concept="22Mrfp" id="3yuK3TkZTGk" role="22Mr8z" />
        </node>
      </node>
    </node>
    <node concept="3fbQ3u" id="3yuK3TkZTdg" role="3fbPIo">
      <property role="2DRQuN" value="1672927911260" />
      <property role="2DXwbs" value="rijo" />
      <property role="1ylvJX" value="Safety Requirements" />
      <property role="TrG5h" value="safetyReq" />
      <node concept="GmGrk" id="3yuK3TkZTdi" role="GmGcz">
        <node concept="1_0LV8" id="3yuK3TkZTdj" role="1_0VJ0">
          <node concept="19SGf9" id="3yuK3TkZTdk" role="1_0LWR">
            <node concept="19SUe$" id="3yuK3TkZWxO" role="19SJt6" />
          </node>
        </node>
      </node>
      <node concept="22Mrfp" id="3yuK3TkZTdm" role="22Mr8z" />
      <node concept="3fbQ3u" id="3yuK3TkZTdV" role="3fbPAY">
        <property role="2DRQuN" value="1672916128456" />
        <property role="2DXwbs" value="rijo" />
        <property role="1ylvJX" value="Sensor Error Requirements" />
        <property role="TrG5h" value="sensorErrorReq" />
        <node concept="GmGrk" id="3yuK3TkZTdW" role="GmGcz">
          <node concept="1_0LV8" id="3yuK3TkZTdX" role="1_0VJ0">
            <node concept="19SGf9" id="3yuK3TkZTdY" role="1_0LWR">
              <node concept="19SUe$" id="3yuK3TkZTdZ" role="19SJt6">
                <property role="19SUeA" value="When an error is detected, the sensor shall report an error.&#10;Hazards: " />
              </node>
              <node concept="2oIDSw" id="3yuK3TkZWvc" role="19SJt6">
                <ref role="2wPqOu" node="3yuK3TkZUbh" resolve="sensorHazard" />
              </node>
              <node concept="19SUe$" id="3yuK3TkZWvo" role="19SJt6">
                <property role="19SUeA" value="" />
              </node>
            </node>
          </node>
        </node>
        <node concept="22Mrfp" id="3yuK3TkZTe0" role="22Mr8z" />
        <node concept="3fbQ3u" id="3yuK3TkZTSp" role="3fbPAY">
          <property role="2DRQuN" value="1672916128456" />
          <property role="2DXwbs" value="rijo" />
          <property role="1ylvJX" value="Sensor Error handling Requirements" />
          <property role="TrG5h" value="sensorErrorHandleReq" />
          <node concept="GmGrk" id="3yuK3TkZTSq" role="GmGcz">
            <node concept="1_0LV8" id="3yuK3TkZTSr" role="1_0VJ0">
              <node concept="19SGf9" id="3yuK3TkZTSs" role="1_0LWR">
                <node concept="19SUe$" id="3yuK3TkZTSt" role="19SJt6">
                  <property role="19SUeA" value="The system shall have the capacity to handle sensor errors." />
                </node>
              </node>
            </node>
          </node>
          <node concept="22Mrfp" id="3yuK3TkZTSu" role="22Mr8z" />
        </node>
      </node>
      <node concept="3fbQ3u" id="3yuK3TkZU3D" role="3fbPAY">
        <property role="2DRQuN" value="1672927752277" />
        <property role="2DXwbs" value="rijo" />
        <property role="1ylvJX" value="Actuators Error Requirements" />
        <property role="TrG5h" value="actuatorErrorReq" />
        <node concept="GmGrk" id="3yuK3TkZU3E" role="GmGcz">
          <node concept="1_0LV8" id="3yuK3TkZU3F" role="1_0VJ0">
            <node concept="19SGf9" id="3yuK3TkZU3G" role="1_0LWR">
              <node concept="19SUe$" id="3yuK3TkZU3H" role="19SJt6">
                <property role="19SUeA" value="When an error is detected, the actuator shall report an error.&#10;Hazard: " />
              </node>
              <node concept="2oIDSw" id="3yuK3TkZWxA" role="19SJt6">
                <ref role="2wPqOu" node="3yuK3TkZUcf" resolve="actuatorHazard" />
              </node>
              <node concept="19SUe$" id="3yuK3TkZWx_" role="19SJt6">
                <property role="19SUeA" value="" />
              </node>
            </node>
          </node>
        </node>
        <node concept="22Mrfp" id="3yuK3TkZU3I" role="22Mr8z" />
        <node concept="3fbQ3u" id="3yuK3TkZTed" role="3fbPAY">
          <property role="2DRQuN" value="1672916128456" />
          <property role="2DXwbs" value="rijo" />
          <property role="1ylvJX" value="Actuators Error handling Requirements" />
          <property role="TrG5h" value="actuatorErrorHandleReq" />
          <node concept="GmGrk" id="3yuK3TkZTee" role="GmGcz">
            <node concept="1_0LV8" id="3yuK3TkZTef" role="1_0VJ0">
              <node concept="19SGf9" id="3yuK3TkZTeg" role="1_0LWR">
                <node concept="19SUe$" id="3yuK3TkZTeh" role="19SJt6">
                  <property role="19SUeA" value="The system shall have the capacity to to handle actuator errors." />
                </node>
              </node>
            </node>
          </node>
          <node concept="22Mrfp" id="3yuK3TkZTei" role="22Mr8z" />
        </node>
      </node>
      <node concept="3fbQ3u" id="3yuK3TkZWwd" role="3fbPAY">
        <property role="2DRQuN" value="1672916128456" />
        <property role="2DXwbs" value="rijo" />
        <property role="1ylvJX" value="Window Requirements" />
        <property role="TrG5h" value="windowReq" />
        <node concept="GmGrk" id="3yuK3TkZWwe" role="GmGcz">
          <node concept="1_0LV8" id="3yuK3TkZWwf" role="1_0VJ0">
            <node concept="19SGf9" id="3yuK3TkZWwg" role="1_0LWR">
              <node concept="19SUe$" id="3yuK3TkZWwh" role="19SJt6">
                <property role="19SUeA" value="The windows shall have contact switches " />
              </node>
              <node concept="2oIDSw" id="3yuK3TkZWxo" role="19SJt6">
                <ref role="2wPqOu" node="3yuK3TkZVCF" resolve="blindsWindow" />
              </node>
              <node concept="19SUe$" id="3yuK3TkZWxp" role="19SJt6">
                <property role="19SUeA" value=" to check window status.&#10;Hazard: " />
              </node>
              <node concept="2oIDSw" id="3yuK3TkZWx9" role="19SJt6">
                <ref role="2wPqOu" node="3yuK3TkZUgZ" resolve="windowSecHazard" />
              </node>
              <node concept="19SUe$" id="3yuK3TkZWxa" role="19SJt6" />
            </node>
          </node>
        </node>
        <node concept="22Mrfp" id="3yuK3TkZWwi" role="22Mr8z" />
      </node>
    </node>
    <node concept="OjmMv" id="3yuK3TkZPU_" role="tLAhV">
      <node concept="19SGf9" id="3yuK3TkZPUA" role="OjmMu">
        <node concept="19SUe$" id="3yuK3TkZPUB" role="19SJt6" />
      </node>
    </node>
    <node concept="2RsZnQ" id="3yuK3TkZPUC" role="2RsZnW" />
    <node concept="3GEVxB" id="3yuK3TkZT7J" role="1BwUYK">
      <ref role="3GEb4d" node="3yuK3TkZSYP" resolve="UseCases" />
    </node>
    <node concept="3GEVxB" id="3yuK3TkZT7O" role="1BwUYK">
      <ref role="3GEb4d" node="3yuK3TkZT14" resolve="Components" />
    </node>
    <node concept="3GEVxB" id="3yuK3TkZT7W" role="1BwUYK">
      <ref role="3GEb4d" node="3yuK3TkZT3h" resolve="Actors" />
    </node>
    <node concept="3GEVxB" id="3yuK3TkZT86" role="1BwUYK">
      <ref role="3GEb4d" node="3yuK3TkZT5u" resolve="Hazards" />
    </node>
    <node concept="3GEVxB" id="3yuK3TkZWM8" role="1BwUYK">
      <ref role="3GEb4d" node="3yuK3TkZWDd" resolve="Parameters" />
    </node>
  </node>
  <node concept="2SbYGP" id="3yuK3TkZPUD">
    <property role="TrG5h" value="DefaultDocConfig" />
    <node concept="2SbYGw" id="3yuK3TkZPUE" role="Cbewh">
      <property role="TrG5h" value="temp" />
      <node concept="9PVaO" id="3yuK3TkZPUF" role="9PVG_">
        <property role="3N1Lgt" value="." />
      </node>
    </node>
    <node concept="2SbYGw" id="3yuK3TkZT6B" role="A10yx">
      <property role="TrG5h" value="img" />
      <node concept="9PVaO" id="3yuK3TkZT6C" role="9PVG_">
        <property role="3N1Lgt" value="." />
      </node>
    </node>
  </node>
  <node concept="3fbPIq" id="3yuK3TkZSYP">
    <property role="TrG5h" value="UseCases" />
    <ref role="G9hjw" node="3yuK3TkZPUD" resolve="DefaultDocConfig" />
    <node concept="OjmMv" id="3yuK3TkZSYQ" role="tLAhV">
      <node concept="19SGf9" id="3yuK3TkZSYR" role="OjmMu">
        <node concept="19SUe$" id="3yuK3TkZSYS" role="19SJt6" />
      </node>
    </node>
    <node concept="2RsZnQ" id="3yuK3TkZSYT" role="2RsZnW" />
    <node concept="3GEVxB" id="53MU4peydKv" role="1BwUYK">
      <ref role="3GEb4d" node="3yuK3TkZT3h" resolve="Actors" />
    </node>
    <node concept="3GEVxB" id="53MU4peydK$" role="1BwUYK">
      <ref role="3GEb4d" node="3yuK3TkZT14" resolve="Components" />
    </node>
    <node concept="3fbQ3u" id="53MU4peydKD" role="3fbPIo">
      <property role="2DRQuN" value="1673605426861" />
      <property role="2DXwbs" value="rijo" />
      <property role="1ylvJX" value="System in Auto Mode" />
      <property role="TrG5h" value="autoMode" />
      <node concept="GmGrk" id="53MU4peydKF" role="GmGcz">
        <node concept="1_0LV8" id="53MU4peydKG" role="1_0VJ0">
          <node concept="19SGf9" id="53MU4peydKH" role="1_0LWR">
            <node concept="19SUe$" id="53MU4peydKI" role="19SJt6" />
          </node>
        </node>
      </node>
      <node concept="4R1oT" id="53MU4peydKC" role="22Mr8z" />
      <node concept="oTeIi" id="53MU4peydV6" role="3faCKd" />
      <node concept="4R1oW" id="53MU4peye62" role="3faCKd">
        <property role="TrG5h" value="getRoomStatus" />
        <node concept="4RctY" id="53MU4peye63" role="4Rctc">
          <node concept="16N2To" id="53MU4peye64" role="4RctW">
            <ref role="16N2Tp" node="3yuK3TkZVDZ" resolve="hmi" />
          </node>
        </node>
        <node concept="4RctY" id="53MU4peyeb2" role="4Rctc">
          <node concept="16N2To" id="53MU4peyeb4" role="4RctW">
            <ref role="16N2Tp" node="3yuK3TkZTs4" resolve="maintenanceDep" />
          </node>
        </node>
        <node concept="4R9Ek" id="53MU4peye65" role="4Rctc">
          <node concept="16N2To" id="53MU4peye66" role="4R9Ej">
            <ref role="16N2Tp" node="3yuK3TkZVy_" resolve="controlUnit" />
          </node>
        </node>
      </node>
      <node concept="4R1oW" id="53MU4peydKP" role="3faCKd">
        <property role="TrG5h" value="controlSystem" />
        <node concept="4RctY" id="53MU4peydKT" role="4Rctc">
          <node concept="16N2To" id="53MU4peydKV" role="4RctW">
            <ref role="16N2Tp" node="3yuK3TkZVy_" resolve="controlUnit" />
          </node>
        </node>
        <node concept="4R9Ek" id="53MU4peydL3" role="4Rctc">
          <node concept="16N2To" id="53MU4peydL5" role="4R9Ej">
            <ref role="16N2Tp" node="3yuK3TkZVLu" resolve="ambLightController" />
          </node>
        </node>
        <node concept="4R9Ek" id="53MU4peydOV" role="4Rctc">
          <node concept="16N2To" id="53MU4peydOX" role="4R9Ej">
            <ref role="16N2Tp" node="3yuK3TkZVC4" resolve="blindsController" />
          </node>
        </node>
        <node concept="4R9Ek" id="53MU4peydPd" role="4Rctc">
          <node concept="16N2To" id="53MU4peydPf" role="4R9Ej">
            <ref role="16N2Tp" node="3yuK3TkZV_w" resolve="heaterController" />
          </node>
        </node>
        <node concept="4R9Ek" id="53MU4peydPz" role="4Rctc">
          <node concept="16N2To" id="53MU4peydP_" role="4R9Ej">
            <ref role="16N2Tp" node="3yuK3TkZVBM" resolve="lightsController" />
          </node>
        </node>
        <node concept="4R9Ek" id="53MU4peydPX" role="4Rctc">
          <node concept="16N2To" id="53MU4peydPZ" role="4R9Ej">
            <ref role="16N2Tp" node="3yuK3TkZVIe" resolve="tempController" />
          </node>
        </node>
      </node>
      <node concept="4R1oW" id="53MU4peydUA" role="3faCKd">
        <property role="TrG5h" value="getAmbientLightValue" />
        <node concept="4RctY" id="53MU4peydWr" role="4Rctc">
          <node concept="16N2To" id="53MU4peydWs" role="4RctW">
            <ref role="16N2Tp" node="3yuK3TkZVLu" resolve="ambLightController" />
          </node>
        </node>
        <node concept="4R9Ek" id="53MU4peydWz" role="4Rctc">
          <node concept="16N2To" id="53MU4peydW_" role="4R9Ej">
            <ref role="16N2Tp" node="3yuK3TkZVLm" resolve="amblightSensor" />
          </node>
        </node>
      </node>
      <node concept="4R1oW" id="53MU4peydX4" role="3faCKd">
        <property role="TrG5h" value="getTemperatureValue" />
        <node concept="4RctY" id="53MU4peydX5" role="4Rctc">
          <node concept="16N2To" id="53MU4peydX6" role="4RctW">
            <ref role="16N2Tp" node="3yuK3TkZVIe" resolve="tempController" />
          </node>
        </node>
        <node concept="4R9Ek" id="53MU4peydX7" role="4Rctc">
          <node concept="16N2To" id="53MU4peydX8" role="4R9Ej">
            <ref role="16N2Tp" node="3yuK3TkZVI6" resolve="tempSensor" />
          </node>
        </node>
      </node>
      <node concept="4R1oW" id="53MU4peydYE" role="3faCKd">
        <property role="TrG5h" value="changeBlinds" />
        <node concept="4RctY" id="53MU4peydYF" role="4Rctc">
          <node concept="16N2To" id="53MU4peydYG" role="4RctW">
            <ref role="16N2Tp" node="3yuK3TkZVC4" resolve="blindsController" />
          </node>
        </node>
        <node concept="4R9Ek" id="53MU4peydYH" role="4Rctc">
          <node concept="16N2To" id="53MU4peydYI" role="4R9Ej">
            <ref role="16N2Tp" node="3yuK3TkZVCm" resolve="blindsMotor" />
          </node>
        </node>
      </node>
      <node concept="4R1oW" id="53MU4peye0r" role="3faCKd">
        <property role="TrG5h" value="getBlindsPosition" />
        <node concept="4RctY" id="53MU4peye0s" role="4Rctc">
          <node concept="16N2To" id="53MU4peye0t" role="4RctW">
            <ref role="16N2Tp" node="3yuK3TkZVC4" resolve="blindsController" />
          </node>
        </node>
        <node concept="4R9Ek" id="53MU4peye0u" role="4Rctc">
          <node concept="16N2To" id="53MU4peye0v" role="4R9Ej">
            <ref role="16N2Tp" node="3yuK3TkZVUO" resolve="blindsPosition" />
          </node>
        </node>
      </node>
      <node concept="4R1oW" id="53MU4peydZw" role="3faCKd">
        <property role="TrG5h" value="moveBlinds" />
        <node concept="4RctY" id="53MU4peydZx" role="4Rctc">
          <node concept="16N2To" id="53MU4peydZy" role="4RctW">
            <ref role="16N2Tp" node="3yuK3TkZVCm" resolve="blindsMotor" />
          </node>
        </node>
        <node concept="4R9Ek" id="53MU4peydZz" role="4Rctc">
          <node concept="16N2To" id="53MU4peydZ$" role="4R9Ej">
            <ref role="16N2Tp" node="3yuK3TkZV$T" resolve="blinds" />
          </node>
        </node>
      </node>
      <node concept="4R1oW" id="53MU4peye17" role="3faCKd">
        <property role="TrG5h" value="changeTemperature" />
        <node concept="4RctY" id="53MU4peye18" role="4Rctc">
          <node concept="16N2To" id="53MU4peye19" role="4RctW">
            <ref role="16N2Tp" node="3yuK3TkZV_w" resolve="heaterController" />
          </node>
        </node>
        <node concept="4R9Ek" id="53MU4peye1a" role="4Rctc">
          <node concept="16N2To" id="53MU4peye1b" role="4R9Ej">
            <ref role="16N2Tp" node="53MU4peye1Y" resolve="heaterValve" />
          </node>
        </node>
      </node>
      <node concept="4R1oW" id="53MU4peye4h" role="3faCKd">
        <property role="TrG5h" value="changeHeaterValve" />
        <node concept="4RctY" id="53MU4peye4i" role="4Rctc">
          <node concept="16N2To" id="53MU4peye4j" role="4RctW">
            <ref role="16N2Tp" node="53MU4peye1Y" resolve="heaterValve" />
          </node>
        </node>
        <node concept="4R9Ek" id="53MU4peye4k" role="4Rctc">
          <node concept="16N2To" id="53MU4peye4l" role="4R9Ej">
            <ref role="16N2Tp" node="3yuK3TkZVzx" resolve="heater" />
          </node>
        </node>
      </node>
      <node concept="4R1oW" id="53MU4peye57" role="3faCKd">
        <property role="TrG5h" value="changeLights" />
        <node concept="4RctY" id="53MU4peye58" role="4Rctc">
          <node concept="16N2To" id="53MU4peye59" role="4RctW">
            <ref role="16N2Tp" node="3yuK3TkZVBM" resolve="lightsController" />
          </node>
        </node>
        <node concept="4R9Ek" id="53MU4peye5a" role="4Rctc">
          <node concept="16N2To" id="53MU4peye5b" role="4R9Ej">
            <ref role="16N2Tp" node="3yuK3TkZV$q" resolve="lights" />
          </node>
        </node>
      </node>
    </node>
    <node concept="3fbQ3u" id="53MU4peyedp" role="3fbPIo">
      <property role="2DRQuN" value="1673605426861" />
      <property role="2DXwbs" value="rijo" />
      <property role="1ylvJX" value="System in Manual Mode" />
      <property role="TrG5h" value="manualMode" />
      <node concept="GmGrk" id="53MU4peyedq" role="GmGcz">
        <node concept="1_0LV8" id="53MU4peyedr" role="1_0VJ0">
          <node concept="19SGf9" id="53MU4peyeds" role="1_0LWR">
            <node concept="19SUe$" id="53MU4peyedt" role="19SJt6" />
          </node>
        </node>
      </node>
      <node concept="4R1oT" id="53MU4peyedu" role="22Mr8z" />
      <node concept="oTeIi" id="53MU4peyedv" role="3faCKd" />
      <node concept="4R1oW" id="53MU4peyejL" role="3faCKd">
        <property role="TrG5h" value="userControl" />
        <node concept="4RctY" id="53MU4peyejM" role="4Rctc">
          <node concept="16N2To" id="53MU4peyejN" role="4RctW">
            <ref role="16N2Tp" node="3yuK3TkZTrV" resolve="user" />
          </node>
        </node>
        <node concept="4R9Ek" id="53MU4peyejQ" role="4Rctc">
          <node concept="16N2To" id="53MU4peyejR" role="4R9Ej">
            <ref role="16N2Tp" node="3yuK3TkZVDZ" resolve="hmi" />
          </node>
        </node>
      </node>
      <node concept="4R1oW" id="53MU4peyedw" role="3faCKd">
        <property role="TrG5h" value="getRoomStatus" />
        <node concept="4RctY" id="53MU4peyedx" role="4Rctc">
          <node concept="16N2To" id="53MU4peyedy" role="4RctW">
            <ref role="16N2Tp" node="3yuK3TkZVDZ" resolve="hmi" />
          </node>
        </node>
        <node concept="4RctY" id="53MU4peyedz" role="4Rctc">
          <node concept="16N2To" id="53MU4peyed$" role="4RctW">
            <ref role="16N2Tp" node="3yuK3TkZTs4" resolve="maintenanceDep" />
          </node>
        </node>
        <node concept="4R9Ek" id="53MU4peyed_" role="4Rctc">
          <node concept="16N2To" id="53MU4peyedA" role="4R9Ej">
            <ref role="16N2Tp" node="3yuK3TkZVy_" resolve="controlUnit" />
          </node>
        </node>
      </node>
      <node concept="4R1oW" id="53MU4peyedB" role="3faCKd">
        <property role="TrG5h" value="controlSystem" />
        <node concept="4RctY" id="53MU4peyedC" role="4Rctc">
          <node concept="16N2To" id="53MU4peyedD" role="4RctW">
            <ref role="16N2Tp" node="3yuK3TkZVy_" resolve="controlUnit" />
          </node>
        </node>
        <node concept="4R9Ek" id="53MU4peyedE" role="4Rctc">
          <node concept="16N2To" id="53MU4peyedF" role="4R9Ej">
            <ref role="16N2Tp" node="3yuK3TkZVLu" resolve="ambLightController" />
          </node>
        </node>
        <node concept="4R9Ek" id="53MU4peyedG" role="4Rctc">
          <node concept="16N2To" id="53MU4peyedH" role="4R9Ej">
            <ref role="16N2Tp" node="3yuK3TkZVC4" resolve="blindsController" />
          </node>
        </node>
        <node concept="4R9Ek" id="53MU4peyedI" role="4Rctc">
          <node concept="16N2To" id="53MU4peyedJ" role="4R9Ej">
            <ref role="16N2Tp" node="3yuK3TkZV_w" resolve="heaterController" />
          </node>
        </node>
        <node concept="4R9Ek" id="53MU4peyedK" role="4Rctc">
          <node concept="16N2To" id="53MU4peyedL" role="4R9Ej">
            <ref role="16N2Tp" node="3yuK3TkZVBM" resolve="lightsController" />
          </node>
        </node>
        <node concept="4R9Ek" id="53MU4peyedM" role="4Rctc">
          <node concept="16N2To" id="53MU4peyedN" role="4R9Ej">
            <ref role="16N2Tp" node="3yuK3TkZVIe" resolve="tempController" />
          </node>
        </node>
      </node>
      <node concept="4R1oW" id="53MU4peyedO" role="3faCKd">
        <property role="TrG5h" value="getAmbientLightValue" />
        <node concept="4RctY" id="53MU4peyedP" role="4Rctc">
          <node concept="16N2To" id="53MU4peyedQ" role="4RctW">
            <ref role="16N2Tp" node="3yuK3TkZVLu" resolve="ambLightController" />
          </node>
        </node>
        <node concept="4R9Ek" id="53MU4peyedR" role="4Rctc">
          <node concept="16N2To" id="53MU4peyedS" role="4R9Ej">
            <ref role="16N2Tp" node="3yuK3TkZVLm" resolve="amblightSensor" />
          </node>
        </node>
      </node>
      <node concept="4R1oW" id="53MU4peyedT" role="3faCKd">
        <property role="TrG5h" value="getTemperatureValue" />
        <node concept="4RctY" id="53MU4peyedU" role="4Rctc">
          <node concept="16N2To" id="53MU4peyedV" role="4RctW">
            <ref role="16N2Tp" node="3yuK3TkZVIe" resolve="tempController" />
          </node>
        </node>
        <node concept="4R9Ek" id="53MU4peyedW" role="4Rctc">
          <node concept="16N2To" id="53MU4peyedX" role="4R9Ej">
            <ref role="16N2Tp" node="3yuK3TkZVI6" resolve="tempSensor" />
          </node>
        </node>
      </node>
      <node concept="4R1oW" id="53MU4peyedY" role="3faCKd">
        <property role="TrG5h" value="changeBlinds" />
        <node concept="4RctY" id="53MU4peyedZ" role="4Rctc">
          <node concept="16N2To" id="53MU4peyee0" role="4RctW">
            <ref role="16N2Tp" node="3yuK3TkZVC4" resolve="blindsController" />
          </node>
        </node>
        <node concept="4R9Ek" id="53MU4peyee1" role="4Rctc">
          <node concept="16N2To" id="53MU4peyee2" role="4R9Ej">
            <ref role="16N2Tp" node="3yuK3TkZVCm" resolve="blindsMotor" />
          </node>
        </node>
      </node>
      <node concept="4R1oW" id="53MU4peyee3" role="3faCKd">
        <property role="TrG5h" value="getBlindsPosition" />
        <node concept="4RctY" id="53MU4peyee4" role="4Rctc">
          <node concept="16N2To" id="53MU4peyee5" role="4RctW">
            <ref role="16N2Tp" node="3yuK3TkZVC4" resolve="blindsController" />
          </node>
        </node>
        <node concept="4R9Ek" id="53MU4peyee6" role="4Rctc">
          <node concept="16N2To" id="53MU4peyee7" role="4R9Ej">
            <ref role="16N2Tp" node="3yuK3TkZVUO" resolve="blindsPosition" />
          </node>
        </node>
      </node>
      <node concept="4R1oW" id="53MU4peyee8" role="3faCKd">
        <property role="TrG5h" value="moveBlinds" />
        <node concept="4RctY" id="53MU4peyee9" role="4Rctc">
          <node concept="16N2To" id="53MU4peyeea" role="4RctW">
            <ref role="16N2Tp" node="3yuK3TkZVCm" resolve="blindsMotor" />
          </node>
        </node>
        <node concept="4R9Ek" id="53MU4peyeeb" role="4Rctc">
          <node concept="16N2To" id="53MU4peyeec" role="4R9Ej">
            <ref role="16N2Tp" node="3yuK3TkZV$T" resolve="blinds" />
          </node>
        </node>
      </node>
      <node concept="4R1oW" id="53MU4peyeed" role="3faCKd">
        <property role="TrG5h" value="changeTemperature" />
        <node concept="4RctY" id="53MU4peyeee" role="4Rctc">
          <node concept="16N2To" id="53MU4peyeef" role="4RctW">
            <ref role="16N2Tp" node="3yuK3TkZV_w" resolve="heaterController" />
          </node>
        </node>
        <node concept="4R9Ek" id="53MU4peyeeg" role="4Rctc">
          <node concept="16N2To" id="53MU4peyeeh" role="4R9Ej">
            <ref role="16N2Tp" node="53MU4peye1Y" resolve="heaterValve" />
          </node>
        </node>
      </node>
      <node concept="4R1oW" id="53MU4peyeei" role="3faCKd">
        <property role="TrG5h" value="changeHeaterValve" />
        <node concept="4RctY" id="53MU4peyeej" role="4Rctc">
          <node concept="16N2To" id="53MU4peyeek" role="4RctW">
            <ref role="16N2Tp" node="53MU4peye1Y" resolve="heaterValve" />
          </node>
        </node>
        <node concept="4R9Ek" id="53MU4peyeel" role="4Rctc">
          <node concept="16N2To" id="53MU4peyeem" role="4R9Ej">
            <ref role="16N2Tp" node="3yuK3TkZVzx" resolve="heater" />
          </node>
        </node>
      </node>
      <node concept="4R1oW" id="53MU4peyeen" role="3faCKd">
        <property role="TrG5h" value="changeLights" />
        <node concept="4RctY" id="53MU4peyeeo" role="4Rctc">
          <node concept="16N2To" id="53MU4peyeep" role="4RctW">
            <ref role="16N2Tp" node="3yuK3TkZVBM" resolve="lightsController" />
          </node>
        </node>
        <node concept="4R9Ek" id="53MU4peyeeq" role="4Rctc">
          <node concept="16N2To" id="53MU4peyeer" role="4R9Ej">
            <ref role="16N2Tp" node="3yuK3TkZV$q" resolve="lights" />
          </node>
        </node>
      </node>
    </node>
  </node>
  <node concept="3fbPIq" id="3yuK3TkZT14">
    <property role="TrG5h" value="Components" />
    <ref role="G9hjw" node="3yuK3TkZPUD" resolve="DefaultDocConfig" />
    <node concept="OjmMv" id="3yuK3TkZT15" role="tLAhV">
      <node concept="19SGf9" id="3yuK3TkZT16" role="OjmMu">
        <node concept="19SUe$" id="3yuK3TkZT17" role="19SJt6" />
      </node>
    </node>
    <node concept="2RsZnQ" id="3yuK3TkZT18" role="2RsZnW" />
    <node concept="3fbQ3u" id="3yuK3TkZVy5" role="3fbPIo">
      <property role="2DRQuN" value="1672997277286" />
      <property role="2DXwbs" value="rijo" />
      <property role="1ylvJX" value="Control Unit" />
      <property role="TrG5h" value="controlUnit" />
      <node concept="GmGrk" id="3yuK3TkZVy7" role="GmGcz">
        <node concept="1_0LV8" id="3yuK3TkZVy8" role="1_0VJ0">
          <node concept="19SGf9" id="3yuK3TkZVy9" role="1_0LWR">
            <node concept="19SUe$" id="3yuK3TkZVya" role="19SJt6" />
          </node>
        </node>
      </node>
      <node concept="16N1iO" id="3yuK3TkZVy4" role="22Mr8z" />
      <node concept="16NEbp" id="3yuK3TkZVy_" role="3faCKd">
        <property role="TrG5h" value="controlUnit" />
        <node concept="16NEbR" id="3yuK3TkZWlQ" role="16NEbj">
          <property role="TrG5h" value="receiveErrors" />
        </node>
        <node concept="16NEbR" id="3yuK3TkZWlS" role="16NEbj">
          <property role="TrG5h" value="sendErrors" />
        </node>
        <node concept="16NEbR" id="3yuK3TkZWp1" role="16NEbj">
          <property role="TrG5h" value="controlLights" />
        </node>
        <node concept="16NEbR" id="3yuK3TkZWp2" role="16NEbj">
          <property role="TrG5h" value="controlBlinds" />
        </node>
        <node concept="16NEbR" id="3yuK3TkZWp3" role="16NEbj">
          <property role="TrG5h" value="controlheater" />
        </node>
        <node concept="16NEbR" id="3yuK3TkZWpw" role="16NEbj">
          <property role="TrG5h" value="receiveSensorData" />
        </node>
        <node concept="16Ny3_" id="3yuK3TkZVH0" role="16NEbj">
          <ref role="16Ny3F" node="3yuK3TkZVDZ" resolve="hmi" />
        </node>
        <node concept="16Ny3_" id="3yuK3TkZVH5" role="16NEbj">
          <ref role="16Ny3F" node="3yuK3TkZVFw" resolve="cardBay" />
        </node>
        <node concept="16Ny3_" id="3yuK3TkZVHd" role="16NEbj">
          <ref role="16Ny3F" node="3yuK3TkZVC4" resolve="blindsController" />
        </node>
        <node concept="16Ny3_" id="3yuK3TkZVHn" role="16NEbj">
          <ref role="16Ny3F" node="3yuK3TkZV_w" resolve="heaterController" />
        </node>
        <node concept="16Ny3_" id="3yuK3TkZVHz" role="16NEbj">
          <ref role="16Ny3F" node="3yuK3TkZVBM" resolve="lightsController" />
        </node>
        <node concept="16Ny3_" id="3yuK3TkZVXE" role="16NEbj">
          <ref role="16Ny3F" node="3yuK3TkZVLu" resolve="lightController" />
        </node>
        <node concept="16Ny3_" id="3yuK3TkZVXU" role="16NEbj">
          <ref role="16Ny3F" node="3yuK3TkZVIe" resolve="tempController" />
        </node>
        <node concept="16Ny3_" id="3yuK3TkZW74" role="16NEbj">
          <ref role="16Ny3F" node="3yuK3TkZW3l" resolve="ui" />
        </node>
      </node>
      <node concept="3fbQ3u" id="3yuK3TkZVDT" role="3fbPAY">
        <property role="2DRQuN" value="1672997277286" />
        <property role="2DXwbs" value="rijo" />
        <property role="1ylvJX" value="HMI" />
        <property role="TrG5h" value="hmi" />
        <node concept="GmGrk" id="3yuK3TkZVDU" role="GmGcz">
          <node concept="1_0LV8" id="3yuK3TkZVDV" role="1_0VJ0">
            <node concept="19SGf9" id="3yuK3TkZVDW" role="1_0LWR">
              <node concept="19SUe$" id="3yuK3TkZVDX" role="19SJt6" />
            </node>
          </node>
        </node>
        <node concept="16N1iO" id="3yuK3TkZVDY" role="22Mr8z" />
        <node concept="16NEbp" id="3yuK3TkZVDZ" role="3faCKd">
          <property role="TrG5h" value="hmi" />
          <node concept="16NEbR" id="3yuK3TkZWmJ" role="16NEbj">
            <property role="TrG5h" value="manuallyControlLights" />
          </node>
          <node concept="16NEbR" id="3yuK3TkZWmK" role="16NEbj">
            <property role="TrG5h" value="manuallyControlBlinds" />
          </node>
          <node concept="16NEbR" id="3yuK3TkZWmL" role="16NEbj">
            <property role="TrG5h" value="manuallyControlheater" />
          </node>
          <node concept="16NEbR" id="3yuK3TkZWmM" role="16NEbj">
            <property role="TrG5h" value="defineOfficeParameters" />
          </node>
          <node concept="16NEbR" id="3yuK3TkZWNr" role="16NEbj">
            <property role="TrG5h" value="showOfficeStatus" />
          </node>
          <node concept="16NEbR" id="3yuK3TkZWn3" role="16NEbj">
            <property role="TrG5h" value="sendErrors" />
          </node>
          <node concept="16Ny3_" id="3yuK3TkZW7o" role="16NEbj">
            <ref role="16Ny3F" node="3yuK3TkZTrV" resolve="user" />
          </node>
          <node concept="16Ny3_" id="3yuK3TkZW7I" role="16NEbj">
            <ref role="16Ny3F" node="3yuK3TkZTs4" resolve="maintenanceDep" />
          </node>
          <node concept="16Ny3_" id="3yuK3TkZVFn" role="16NEbj">
            <ref role="16Ny3F" node="3yuK3TkZVy_" resolve="controlUnit" />
          </node>
        </node>
      </node>
      <node concept="3fbQ3u" id="3yuK3TkZVFq" role="3fbPAY">
        <property role="2DRQuN" value="1672997277286" />
        <property role="2DXwbs" value="rijo" />
        <property role="1ylvJX" value="Card Bay" />
        <property role="TrG5h" value="cardBay" />
        <node concept="GmGrk" id="3yuK3TkZVFr" role="GmGcz">
          <node concept="1_0LV8" id="3yuK3TkZVFs" role="1_0VJ0">
            <node concept="19SGf9" id="3yuK3TkZVFt" role="1_0LWR">
              <node concept="19SUe$" id="3yuK3TkZVFu" role="19SJt6" />
            </node>
          </node>
        </node>
        <node concept="16N1iO" id="3yuK3TkZVFv" role="22Mr8z" />
        <node concept="16NEbp" id="3yuK3TkZVFw" role="3faCKd">
          <property role="TrG5h" value="cardBay" />
          <node concept="16NEbR" id="3yuK3TkZWmE" role="16NEbj">
            <property role="TrG5h" value="detectCard" />
          </node>
          <node concept="16Ny3_" id="3yuK3TkZW88" role="16NEbj">
            <ref role="16Ny3F" node="3yuK3TkZTrV" resolve="user" />
          </node>
          <node concept="16Ny3_" id="3yuK3TkZVGY" role="16NEbj">
            <ref role="16Ny3F" node="3yuK3TkZVy_" resolve="controlUnit" />
          </node>
        </node>
      </node>
    </node>
    <node concept="3fbQ3u" id="3yuK3TkZW3f" role="3fbPIo">
      <property role="2DRQuN" value="1672997277286" />
      <property role="2DXwbs" value="rijo" />
      <property role="1ylvJX" value="Maintenance department UI" />
      <property role="TrG5h" value="ui" />
      <node concept="GmGrk" id="3yuK3TkZW3g" role="GmGcz">
        <node concept="1_0LV8" id="3yuK3TkZW3h" role="1_0VJ0">
          <node concept="19SGf9" id="3yuK3TkZW3i" role="1_0LWR">
            <node concept="19SUe$" id="3yuK3TkZW3j" role="19SJt6" />
          </node>
        </node>
      </node>
      <node concept="16N1iO" id="3yuK3TkZW3k" role="22Mr8z" />
      <node concept="16NEbp" id="3yuK3TkZW3l" role="3faCKd">
        <property role="TrG5h" value="ui" />
        <node concept="16NEbR" id="3yuK3TkZWjT" role="16NEbj">
          <property role="TrG5h" value="receiveErrors" />
        </node>
        <node concept="16NEbR" id="3yuK3TkZWk3" role="16NEbj">
          <property role="TrG5h" value="receiveOfficeEnviromentStatus" />
        </node>
        <node concept="16NEbR" id="3yuK3TkZWkk" role="16NEbj">
          <property role="TrG5h" value="controlLights" />
        </node>
        <node concept="16NEbR" id="3yuK3TkZWky" role="16NEbj">
          <property role="TrG5h" value="controlBlinds" />
        </node>
        <node concept="16NEbR" id="3yuK3TkZWkL" role="16NEbj">
          <property role="TrG5h" value="controlheater" />
        </node>
        <node concept="16NEbR" id="3yuK3TkZWl2" role="16NEbj">
          <property role="TrG5h" value="defineOfficeParameters" />
        </node>
        <node concept="16NEbR" id="3yuK3TkZWll" role="16NEbj">
          <property role="TrG5h" value="blockUser" />
        </node>
        <node concept="16NEbR" id="3yuK3TkZWNA" role="16NEbj">
          <property role="TrG5h" value="showOfficeStatus" />
        </node>
        <node concept="16NEbR" id="3yuK3TkZWlE" role="16NEbj">
          <property role="TrG5h" value="overrideSettings" />
        </node>
        <node concept="16Ny3_" id="3yuK3TkZW7U" role="16NEbj">
          <ref role="16Ny3F" node="3yuK3TkZTs4" resolve="maintenanceDep" />
        </node>
        <node concept="16Ny3_" id="3yuK3TkZW3m" role="16NEbj">
          <ref role="16Ny3F" node="3yuK3TkZVy_" resolve="controlUnit" />
        </node>
      </node>
    </node>
    <node concept="3fbQ3u" id="3yuK3TkZVyC" role="3fbPIo">
      <property role="2DRQuN" value="1672997353806" />
      <property role="2DXwbs" value="rijo" />
      <property role="1ylvJX" value="Smart Heater" />
      <property role="TrG5h" value="heater" />
      <node concept="GmGrk" id="3yuK3TkZVyE" role="GmGcz">
        <node concept="1_0LV8" id="3yuK3TkZVyF" role="1_0VJ0">
          <node concept="19SGf9" id="3yuK3TkZVyG" role="1_0LWR">
            <node concept="19SUe$" id="3yuK3TkZVyH" role="19SJt6" />
          </node>
        </node>
      </node>
      <node concept="16N1iO" id="3yuK3TkZVzs" role="22Mr8z" />
      <node concept="16NEbp" id="3yuK3TkZVzx" role="3faCKd">
        <property role="TrG5h" value="heater" />
        <node concept="16NEbR" id="3yuK3TkZWjI" role="16NEbj">
          <property role="TrG5h" value="turnOn" />
        </node>
        <node concept="16NEbR" id="3yuK3TkZWjJ" role="16NEbj">
          <property role="TrG5h" value="turnOff" />
        </node>
        <node concept="16NEbR" id="3yuK3TkZWjK" role="16NEbj">
          <property role="TrG5h" value="increaseTemperature" />
        </node>
        <node concept="16Ny3_" id="3yuK3TkZVBE" role="16NEbj">
          <ref role="16Ny3F" node="3yuK3TkZV_w" resolve="heaterController" />
        </node>
      </node>
      <node concept="3fbQ3u" id="3yuK3TkZV_q" role="3fbPAY">
        <property role="2DRQuN" value="1672997353806" />
        <property role="2DXwbs" value="rijo" />
        <property role="1ylvJX" value="Smart Heater Controller" />
        <property role="TrG5h" value="heaterController" />
        <node concept="GmGrk" id="3yuK3TkZV_r" role="GmGcz">
          <node concept="1_0LV8" id="3yuK3TkZV_s" role="1_0VJ0">
            <node concept="19SGf9" id="3yuK3TkZV_t" role="1_0LWR">
              <node concept="19SUe$" id="3yuK3TkZV_u" role="19SJt6" />
            </node>
          </node>
        </node>
        <node concept="16N1iO" id="3yuK3TkZV_v" role="22Mr8z" />
        <node concept="16NEbp" id="3yuK3TkZV_w" role="3faCKd">
          <property role="TrG5h" value="heaterController" />
          <node concept="16NEbR" id="3yuK3TkZWjx" role="16NEbj">
            <property role="TrG5h" value="receiveCommandToTurnOn" />
          </node>
          <node concept="16NEbR" id="3yuK3TkZWjy" role="16NEbj">
            <property role="TrG5h" value="receiveCommandToTurnOff" />
          </node>
          <node concept="16NEbR" id="3yuK3TkZWjz" role="16NEbj">
            <property role="TrG5h" value="receiveCommandToIncreaseTemperature" />
          </node>
          <node concept="16Ny3_" id="3yuK3TkZV_x" role="16NEbj">
            <ref role="16Ny3F" node="3yuK3TkZVy_" resolve="controlUnit" />
          </node>
          <node concept="16Ny3_" id="3yuK3TkZVAd" role="16NEbj">
            <ref role="16Ny3F" node="53MU4peye1Y" resolve="heaterValve" />
          </node>
        </node>
      </node>
      <node concept="3fbQ3u" id="53MU4peye1S" role="3fbPAY">
        <property role="2DRQuN" value="1672997353806" />
        <property role="2DXwbs" value="rijo" />
        <property role="1ylvJX" value="Smart Heater Valve" />
        <property role="TrG5h" value="heaterValve" />
        <node concept="GmGrk" id="53MU4peye1T" role="GmGcz">
          <node concept="1_0LV8" id="53MU4peye1U" role="1_0VJ0">
            <node concept="19SGf9" id="53MU4peye1V" role="1_0LWR">
              <node concept="19SUe$" id="53MU4peye1W" role="19SJt6" />
            </node>
          </node>
        </node>
        <node concept="16N1iO" id="53MU4peye1X" role="22Mr8z" />
        <node concept="16NEbp" id="53MU4peye1Y" role="3faCKd">
          <property role="TrG5h" value="heaterValve" />
          <node concept="16NEbR" id="53MU4peye1Z" role="16NEbj">
            <property role="TrG5h" value="close" />
          </node>
          <node concept="16NEbR" id="53MU4peye20" role="16NEbj">
            <property role="TrG5h" value="open" />
          </node>
          <node concept="16Ny3_" id="53MU4peye22" role="16NEbj">
            <ref role="16Ny3F" node="3yuK3TkZV_w" resolve="heaterController" />
          </node>
          <node concept="16Ny3_" id="53MU4peye23" role="16NEbj">
            <ref role="16Ny3F" node="3yuK3TkZVzx" resolve="heater" />
          </node>
        </node>
      </node>
    </node>
    <node concept="3fbQ3u" id="3yuK3TkZV$k" role="3fbPIo">
      <property role="2DRQuN" value="1672997353806" />
      <property role="2DXwbs" value="rijo" />
      <property role="1ylvJX" value="Smart Lights" />
      <property role="TrG5h" value="lights" />
      <node concept="GmGrk" id="3yuK3TkZV$l" role="GmGcz">
        <node concept="1_0LV8" id="3yuK3TkZV$m" role="1_0VJ0">
          <node concept="19SGf9" id="3yuK3TkZV$n" role="1_0LWR">
            <node concept="19SUe$" id="3yuK3TkZV$o" role="19SJt6" />
          </node>
        </node>
      </node>
      <node concept="16N1iO" id="3yuK3TkZV$p" role="22Mr8z" />
      <node concept="16NEbp" id="3yuK3TkZV$q" role="3faCKd">
        <property role="TrG5h" value="lights" />
        <node concept="16NEbR" id="3yuK3TkZWjq" role="16NEbj">
          <property role="TrG5h" value="turnOn" />
        </node>
        <node concept="16NEbR" id="3yuK3TkZWjr" role="16NEbj">
          <property role="TrG5h" value="turnOff" />
        </node>
        <node concept="16NEbR" id="3yuK3TkZWjs" role="16NEbj">
          <property role="TrG5h" value="increaseBrightness" />
        </node>
        <node concept="16NEbR" id="3yuK3TkZWvA" role="16NEbj">
          <property role="TrG5h" value="decreaseBrightness" />
        </node>
        <node concept="16Ny3_" id="3yuK3TkZV$r" role="16NEbj">
          <ref role="16Ny3F" node="3yuK3TkZVBM" resolve="lightsController" />
        </node>
      </node>
      <node concept="3fbQ3u" id="3yuK3TkZVBG" role="3fbPAY">
        <property role="2DRQuN" value="1672997353806" />
        <property role="2DXwbs" value="rijo" />
        <property role="1ylvJX" value="Smart Lights Controller" />
        <property role="TrG5h" value="lightsController" />
        <node concept="GmGrk" id="3yuK3TkZVBH" role="GmGcz">
          <node concept="1_0LV8" id="3yuK3TkZVBI" role="1_0VJ0">
            <node concept="19SGf9" id="3yuK3TkZVBJ" role="1_0LWR">
              <node concept="19SUe$" id="3yuK3TkZVBK" role="19SJt6" />
            </node>
          </node>
        </node>
        <node concept="16N1iO" id="3yuK3TkZVBL" role="22Mr8z" />
        <node concept="16NEbp" id="3yuK3TkZVBM" role="3faCKd">
          <property role="TrG5h" value="lightsController" />
          <node concept="16NEbR" id="3yuK3TkZWj5" role="16NEbj">
            <property role="TrG5h" value="receiveCommandToTurnOn" />
          </node>
          <node concept="16NEbR" id="3yuK3TkZWj6" role="16NEbj">
            <property role="TrG5h" value="receiveCommandToTurnOff" />
          </node>
          <node concept="16NEbR" id="3yuK3TkZWjf" role="16NEbj">
            <property role="TrG5h" value="receiveCommandToIncreaseBrightness" />
          </node>
          <node concept="16NEbR" id="3yuK3TkZWvH" role="16NEbj">
            <property role="TrG5h" value="receiveCommandToDecreaseBrightness" />
          </node>
          <node concept="16NEbR" id="3yuK3TkZWj7" role="16NEbj">
            <property role="TrG5h" value="sendlightsError" />
          </node>
          <node concept="16Ny3_" id="3yuK3TkZVBN" role="16NEbj">
            <ref role="16Ny3F" node="3yuK3TkZVy_" />
          </node>
          <node concept="16Ny3_" id="3yuK3TkZVBO" role="16NEbj">
            <ref role="16Ny3F" node="3yuK3TkZV$q" resolve="lights" />
          </node>
        </node>
      </node>
    </node>
    <node concept="3fbQ3u" id="3yuK3TkZV$N" role="3fbPIo">
      <property role="2DRQuN" value="1672997353806" />
      <property role="2DXwbs" value="rijo" />
      <property role="1ylvJX" value="Smart Blinds" />
      <property role="TrG5h" value="blinds" />
      <node concept="GmGrk" id="3yuK3TkZV$O" role="GmGcz">
        <node concept="1_0LV8" id="3yuK3TkZV$P" role="1_0VJ0">
          <node concept="19SGf9" id="3yuK3TkZV$Q" role="1_0LWR">
            <node concept="19SUe$" id="3yuK3TkZV$R" role="19SJt6" />
          </node>
        </node>
      </node>
      <node concept="16N1iO" id="3yuK3TkZV$S" role="22Mr8z" />
      <node concept="16NEbp" id="3yuK3TkZV$T" role="3faCKd">
        <property role="TrG5h" value="blinds" />
        <node concept="16NEbR" id="3yuK3TkZWiF" role="16NEbj">
          <property role="TrG5h" value="open" />
        </node>
        <node concept="16NEbR" id="3yuK3TkZWiG" role="16NEbj">
          <property role="TrG5h" value="close" />
        </node>
        <node concept="16Ny3_" id="3yuK3TkZV$U" role="16NEbj">
          <ref role="16Ny3F" node="3yuK3TkZVC4" resolve="blindsController" />
        </node>
      </node>
      <node concept="3fbQ3u" id="3yuK3TkZVBY" role="3fbPAY">
        <property role="2DRQuN" value="1672997353806" />
        <property role="2DXwbs" value="rijo" />
        <property role="1ylvJX" value="Smart Blinds Controller" />
        <property role="TrG5h" value="blindsController" />
        <node concept="GmGrk" id="3yuK3TkZVBZ" role="GmGcz">
          <node concept="1_0LV8" id="3yuK3TkZVC0" role="1_0VJ0">
            <node concept="19SGf9" id="3yuK3TkZVC1" role="1_0LWR">
              <node concept="19SUe$" id="3yuK3TkZVC2" role="19SJt6" />
            </node>
          </node>
        </node>
        <node concept="16N1iO" id="3yuK3TkZVC3" role="22Mr8z" />
        <node concept="16NEbp" id="3yuK3TkZVC4" role="3faCKd">
          <property role="TrG5h" value="blindsController" />
          <node concept="16NEbR" id="3yuK3TkZWiU" role="16NEbj">
            <property role="TrG5h" value="receiveCommandToOpen" />
          </node>
          <node concept="16NEbR" id="3yuK3TkZWiV" role="16NEbj">
            <property role="TrG5h" value="receiveCommandToClose" />
          </node>
          <node concept="16NEbR" id="3yuK3TkZWiW" role="16NEbj">
            <property role="TrG5h" value="sendBlindsError" />
          </node>
          <node concept="16Ny3_" id="3yuK3TkZVC5" role="16NEbj">
            <ref role="16Ny3F" node="3yuK3TkZVy_" />
          </node>
          <node concept="16Ny3_" id="3yuK3TkZVC6" role="16NEbj">
            <ref role="16Ny3F" node="3yuK3TkZV$T" resolve="blinds" />
          </node>
          <node concept="16Ny3_" id="3yuK3TkZVDj" role="16NEbj">
            <ref role="16Ny3F" node="3yuK3TkZVUO" resolve="blindsPosition" />
          </node>
          <node concept="16Ny3_" id="3yuK3TkZVXs" role="16NEbj">
            <ref role="16Ny3F" node="3yuK3TkZVVG" resolve="blindsMotorController" />
          </node>
          <node concept="16Ny3_" id="3yuK3TkZVDt" role="16NEbj">
            <ref role="16Ny3F" node="3yuK3TkZVCL" resolve="blindsWindow" />
          </node>
        </node>
      </node>
      <node concept="3fbQ3u" id="3yuK3TkZVCg" role="3fbPAY">
        <property role="2DRQuN" value="1672997353806" />
        <property role="2DXwbs" value="rijo" />
        <property role="1ylvJX" value="Smart Blinds motor" />
        <property role="TrG5h" value="blindsMotor" />
        <node concept="GmGrk" id="3yuK3TkZVCh" role="GmGcz">
          <node concept="1_0LV8" id="3yuK3TkZVCi" role="1_0VJ0">
            <node concept="19SGf9" id="3yuK3TkZVCj" role="1_0LWR">
              <node concept="19SUe$" id="3yuK3TkZVCk" role="19SJt6" />
            </node>
          </node>
        </node>
        <node concept="16N1iO" id="3yuK3TkZVCl" role="22Mr8z" />
        <node concept="16NEbp" id="3yuK3TkZVCm" role="3faCKd">
          <property role="TrG5h" value="blindsMotor" />
          <node concept="16NEbR" id="3yuK3TkZWis" role="16NEbj">
            <property role="TrG5h" value="moveUp" />
          </node>
          <node concept="16NEbR" id="3yuK3TkZWit" role="16NEbj">
            <property role="TrG5h" value="moveDown" />
          </node>
          <node concept="16Ny3_" id="3yuK3TkZVCn" role="16NEbj">
            <ref role="16Ny3F" node="3yuK3TkZVVG" resolve="blindsMotorController" />
          </node>
          <node concept="16Ny3_" id="3yuK3TkZVCo" role="16NEbj">
            <ref role="16Ny3F" node="3yuK3TkZV$T" resolve="blinds" />
          </node>
        </node>
        <node concept="3fbQ3u" id="3yuK3TkZVVA" role="3fbPAY">
          <property role="2DRQuN" value="1672997353806" />
          <property role="2DXwbs" value="rijo" />
          <property role="1ylvJX" value="Smart Blinds Motor Controller" />
          <property role="TrG5h" value="blindsMotorController" />
          <node concept="GmGrk" id="3yuK3TkZVVB" role="GmGcz">
            <node concept="1_0LV8" id="3yuK3TkZVVC" role="1_0VJ0">
              <node concept="19SGf9" id="3yuK3TkZVVD" role="1_0LWR">
                <node concept="19SUe$" id="3yuK3TkZVVE" role="19SJt6" />
              </node>
            </node>
          </node>
          <node concept="16N1iO" id="3yuK3TkZVVF" role="22Mr8z" />
          <node concept="16NEbp" id="3yuK3TkZVVG" role="3faCKd">
            <property role="TrG5h" value="blindsMotorController" />
            <node concept="16NEbR" id="3yuK3TkZWid" role="16NEbj">
              <property role="TrG5h" value="moveBlindsMotorUp" />
            </node>
            <node concept="16NEbR" id="3yuK3TkZWin" role="16NEbj">
              <property role="TrG5h" value="moveBlindsMotorDown" />
            </node>
            <node concept="16Ny3_" id="3yuK3TkZVVH" role="16NEbj">
              <ref role="16Ny3F" node="3yuK3TkZVC4" resolve="blindsController" />
            </node>
            <node concept="16Ny3_" id="3yuK3TkZVVI" role="16NEbj">
              <ref role="16Ny3F" node="3yuK3TkZVCm" resolve="blindsMotor" />
            </node>
          </node>
        </node>
      </node>
      <node concept="3fbQ3u" id="3yuK3TkZVUI" role="3fbPAY">
        <property role="2DRQuN" value="1672997353806" />
        <property role="2DXwbs" value="rijo" />
        <property role="1ylvJX" value="Smart Blinds Position Contact Switch" />
        <property role="TrG5h" value="blindsPosition" />
        <node concept="GmGrk" id="3yuK3TkZVUJ" role="GmGcz">
          <node concept="1_0LV8" id="3yuK3TkZW8o" role="1_0VJ0">
            <node concept="19SGf9" id="3yuK3TkZW8p" role="1_0LWR">
              <node concept="19SUe$" id="3yuK3TkZW8q" role="19SJt6">
                <property role="19SUeA" value="Quantity needed = 4 (1 for each step of the blinds. 0%, 25%, 50%, 75% and 100% opened)&#10;Quantity to use = 10 (2 for each step of the blinds. 0%, 25%, 50%, 75% and 100% opened)" />
              </node>
            </node>
          </node>
        </node>
        <node concept="16N1iO" id="3yuK3TkZVUN" role="22Mr8z" />
        <node concept="16NEbp" id="3yuK3TkZVUO" role="3faCKd">
          <property role="TrG5h" value="blindsPosition" />
          <node concept="16NEbR" id="3yuK3TkZWgM" role="16NEbj">
            <property role="TrG5h" value="detectBlindsAtPosition0" />
          </node>
          <node concept="16NEbR" id="3yuK3TkZWgW" role="16NEbj">
            <property role="TrG5h" value="detectBlindsAtPosition1" />
          </node>
          <node concept="16NEbR" id="3yuK3TkZWhc" role="16NEbj">
            <property role="TrG5h" value="detectBlindsAtPosition2" />
          </node>
          <node concept="16NEbR" id="3yuK3TkZWhp" role="16NEbj">
            <property role="TrG5h" value="detectBlindsAtPosition3" />
          </node>
          <node concept="16NEbR" id="3yuK3TkZWhC" role="16NEbj">
            <property role="TrG5h" value="detectBlindsAtPosition4" />
          </node>
          <node concept="16Ny3_" id="3yuK3TkZVUP" role="16NEbj">
            <ref role="16Ny3F" node="3yuK3TkZVC4" resolve="blindsController" />
          </node>
          <node concept="16Ny3_" id="3yuK3TkZVUQ" role="16NEbj">
            <ref role="16Ny3F" node="3yuK3TkZV$T" resolve="blinds" />
          </node>
        </node>
      </node>
      <node concept="3fbQ3u" id="3yuK3TkZVCF" role="3fbPAY">
        <property role="2DRQuN" value="1672997353806" />
        <property role="2DXwbs" value="rijo" />
        <property role="1ylvJX" value="Smart Blinds Window Contact Switch" />
        <property role="TrG5h" value="blindsWindow" />
        <node concept="GmGrk" id="3yuK3TkZVCG" role="GmGcz">
          <node concept="1_0LV8" id="3yuK3TkZW8u" role="1_0VJ0">
            <node concept="19SGf9" id="3yuK3TkZW8v" role="1_0LWR">
              <node concept="19SUe$" id="3yuK3TkZW8w" role="19SJt6">
                <property role="19SUeA" value="Quantity needed = 1&#10;Quantity to use = 2" />
              </node>
            </node>
          </node>
        </node>
        <node concept="16N1iO" id="3yuK3TkZVCK" role="22Mr8z" />
        <node concept="16NEbp" id="3yuK3TkZVCL" role="3faCKd">
          <property role="TrG5h" value="blindsWindow" />
          <node concept="16NEbR" id="3yuK3TkZWgf" role="16NEbj">
            <property role="TrG5h" value="detectWindowOpen" />
          </node>
          <node concept="16NEbR" id="3yuK3TkZWgC" role="16NEbj">
            <property role="TrG5h" value="detectWindowClose" />
          </node>
          <node concept="16Ny3_" id="3yuK3TkZVCM" role="16NEbj">
            <ref role="16Ny3F" node="3yuK3TkZVC4" resolve="blindsController" />
          </node>
          <node concept="16Ny3_" id="3yuK3TkZVCN" role="16NEbj">
            <ref role="16Ny3F" node="3yuK3TkZV$T" resolve="blinds" />
          </node>
        </node>
      </node>
    </node>
    <node concept="3fbQ3u" id="3yuK3TkZVI0" role="3fbPIo">
      <property role="2DRQuN" value="1672997353806" />
      <property role="2DXwbs" value="rijo" />
      <property role="1ylvJX" value="Temperature Sensor" />
      <property role="TrG5h" value="tempSensor" />
      <node concept="GmGrk" id="3yuK3TkZVI1" role="GmGcz">
        <node concept="1_0LV8" id="3yuK3TkZVI2" role="1_0VJ0">
          <node concept="19SGf9" id="3yuK3TkZVI3" role="1_0LWR">
            <node concept="19SUe$" id="3yuK3TkZVI4" role="19SJt6">
              <property role="19SUeA" value="Quantity needed = 1&#10;Quantity to use = 2" />
            </node>
          </node>
        </node>
      </node>
      <node concept="16N1iO" id="3yuK3TkZVI5" role="22Mr8z" />
      <node concept="16NEbp" id="3yuK3TkZVI6" role="3faCKd">
        <property role="TrG5h" value="tempSensor" />
        <node concept="16NEbR" id="3yuK3TkZWg8" role="16NEbj">
          <property role="TrG5h" value="readTemperatureValue" />
        </node>
        <node concept="16Ny3_" id="3yuK3TkZVI7" role="16NEbj">
          <ref role="16Ny3F" node="3yuK3TkZVIe" resolve="lightsController" />
        </node>
      </node>
      <node concept="3fbQ3u" id="3yuK3TkZVI8" role="3fbPAY">
        <property role="2DRQuN" value="1672997353806" />
        <property role="2DXwbs" value="rijo" />
        <property role="1ylvJX" value="Temperature Sensor Controller" />
        <property role="TrG5h" value="tempController" />
        <node concept="GmGrk" id="3yuK3TkZVI9" role="GmGcz">
          <node concept="1_0LV8" id="3yuK3TkZVIa" role="1_0VJ0">
            <node concept="19SGf9" id="3yuK3TkZVIb" role="1_0LWR">
              <node concept="19SUe$" id="3yuK3TkZVIc" role="19SJt6" />
            </node>
          </node>
        </node>
        <node concept="16N1iO" id="3yuK3TkZVId" role="22Mr8z" />
        <node concept="16NEbp" id="3yuK3TkZVIe" role="3faCKd">
          <property role="TrG5h" value="tempController" />
          <node concept="16NEbR" id="3yuK3TkZWg0" role="16NEbj">
            <property role="TrG5h" value="receiveTemperatureValues" />
          </node>
          <node concept="16NEbR" id="3yuK3TkZWg1" role="16NEbj">
            <property role="TrG5h" value="sendAverageTemperature" />
          </node>
          <node concept="16NEbR" id="3yuK3TkZWg2" role="16NEbj">
            <property role="TrG5h" value="sendSensorError" />
          </node>
          <node concept="16Ny3_" id="3yuK3TkZVIf" role="16NEbj">
            <ref role="16Ny3F" node="3yuK3TkZVy_" resolve="controlUnit" />
          </node>
          <node concept="16Ny3_" id="3yuK3TkZVIg" role="16NEbj">
            <ref role="16Ny3F" node="3yuK3TkZVI6" resolve="lights" />
          </node>
        </node>
      </node>
    </node>
    <node concept="3fbQ3u" id="3yuK3TkZVLg" role="3fbPIo">
      <property role="2DRQuN" value="1672997353806" />
      <property role="2DXwbs" value="rijo" />
      <property role="1ylvJX" value="Ambient Light Sensor" />
      <property role="TrG5h" value="amblightSensor" />
      <node concept="GmGrk" id="3yuK3TkZVLh" role="GmGcz">
        <node concept="1_0LV8" id="3yuK3TkZW8i" role="1_0VJ0">
          <node concept="19SGf9" id="3yuK3TkZW8j" role="1_0LWR">
            <node concept="19SUe$" id="3yuK3TkZW8k" role="19SJt6">
              <property role="19SUeA" value="Quantity needed = 2 (1 inside and 1 outside of the office)&#10;Quantity to use = 4 (2 inside and 2 outside of the office)" />
            </node>
          </node>
        </node>
      </node>
      <node concept="16N1iO" id="3yuK3TkZVLl" role="22Mr8z" />
      <node concept="16NEbp" id="3yuK3TkZVLm" role="3faCKd">
        <property role="TrG5h" value="amblightSensor" />
        <node concept="16NEbR" id="3yuK3TkZWfm" role="16NEbj">
          <property role="TrG5h" value="readAmbientLightValue" />
        </node>
        <node concept="16Ny3_" id="3yuK3TkZVLn" role="16NEbj">
          <ref role="16Ny3F" node="3yuK3TkZVLu" resolve="lightController" />
        </node>
      </node>
      <node concept="3fbQ3u" id="3yuK3TkZVLo" role="3fbPAY">
        <property role="2DRQuN" value="1672997353806" />
        <property role="2DXwbs" value="rijo" />
        <property role="1ylvJX" value="Ambient Light Sensor Controller" />
        <property role="TrG5h" value="ambLightController" />
        <node concept="GmGrk" id="3yuK3TkZVLp" role="GmGcz">
          <node concept="1_0LV8" id="3yuK3TkZVLq" role="1_0VJ0">
            <node concept="19SGf9" id="3yuK3TkZVLr" role="1_0LWR">
              <node concept="19SUe$" id="3yuK3TkZVLs" role="19SJt6" />
            </node>
          </node>
        </node>
        <node concept="16N1iO" id="3yuK3TkZVLt" role="22Mr8z" />
        <node concept="16NEbp" id="3yuK3TkZVLu" role="3faCKd">
          <property role="TrG5h" value="ambLightController" />
          <node concept="16NEbR" id="3yuK3TkZWfu" role="16NEbj">
            <property role="TrG5h" value="receiveAmbientLightValues" />
          </node>
          <node concept="16NEbR" id="3yuK3TkZWfC" role="16NEbj">
            <property role="TrG5h" value="sendAverageAmbientLight" />
          </node>
          <node concept="16NEbR" id="3yuK3TkZWfT" role="16NEbj">
            <property role="TrG5h" value="sendSensorError" />
          </node>
          <node concept="16Ny3_" id="3yuK3TkZVLv" role="16NEbj">
            <ref role="16Ny3F" node="3yuK3TkZVy_" resolve="controlUnit" />
          </node>
          <node concept="16Ny3_" id="3yuK3TkZVLw" role="16NEbj">
            <ref role="16Ny3F" node="3yuK3TkZVLm" resolve="tempSensor" />
          </node>
        </node>
      </node>
    </node>
    <node concept="3GEVxB" id="3yuK3TkZVHE" role="1BwUYK">
      <ref role="3GEb4d" node="3yuK3TkZPU$" resolve="Requirements" />
    </node>
    <node concept="3GEVxB" id="3yuK3TkZVHJ" role="1BwUYK">
      <ref role="3GEb4d" node="3yuK3TkZT3h" resolve="Actors" />
    </node>
  </node>
  <node concept="3fbPIq" id="3yuK3TkZT3h">
    <property role="TrG5h" value="Actors" />
    <ref role="G9hjw" node="3yuK3TkZPUD" resolve="DefaultDocConfig" />
    <node concept="3fbQ3u" id="3yuK3TkZTrD" role="3fbPIo">
      <property role="2DRQuN" value="1672932493967" />
      <property role="2DXwbs" value="rijo" />
      <property role="1ylvJX" value="User" />
      <property role="TrG5h" value="user" />
      <node concept="GmGrk" id="3yuK3TkZTrF" role="GmGcz">
        <node concept="1_0LV8" id="3yuK3TkZTrG" role="1_0VJ0">
          <node concept="19SGf9" id="3yuK3TkZTrH" role="1_0LWR">
            <node concept="19SUe$" id="3yuK3TkZTrI" role="19SJt6" />
          </node>
        </node>
      </node>
      <node concept="16N1iO" id="3yuK3TkZTrQ" role="22Mr8z" />
      <node concept="16NEbg" id="3yuK3TkZTrV" role="3faCKd">
        <property role="TrG5h" value="user" />
        <node concept="16NEbR" id="WfF1I4h9S8" role="16NEbj">
          <property role="TrG5h" value="interact" />
        </node>
        <node concept="16Ny3_" id="3yuK3TkZWpN" role="16NEbj">
          <property role="16N0M8" value="To see office enviroment, manually control the actuators, set office parameters and send error reports to maintenance department" />
          <ref role="16Ny3F" node="3yuK3TkZVDZ" resolve="hmi" />
        </node>
        <node concept="16Ny3_" id="3yuK3TkZWq4" role="16NEbj">
          <property role="16N0M8" value="To insert ID card" />
          <ref role="16Ny3F" node="3yuK3TkZVFw" resolve="cardBay" />
        </node>
      </node>
    </node>
    <node concept="3fbQ3u" id="3yuK3TkZTrY" role="3fbPIo">
      <property role="2DRQuN" value="1672932493967" />
      <property role="2DXwbs" value="rijo" />
      <property role="1ylvJX" value="Maintenence Department" />
      <property role="TrG5h" value="maintenanceDep" />
      <node concept="GmGrk" id="3yuK3TkZTrZ" role="GmGcz">
        <node concept="1_0LV8" id="3yuK3TkZTs0" role="1_0VJ0">
          <node concept="19SGf9" id="3yuK3TkZTs1" role="1_0LWR">
            <node concept="19SUe$" id="3yuK3TkZTs2" role="19SJt6" />
          </node>
        </node>
      </node>
      <node concept="16N1iO" id="3yuK3TkZTs3" role="22Mr8z" />
      <node concept="16NEbg" id="3yuK3TkZTs4" role="3faCKd">
        <property role="TrG5h" value="maintenanceDep" />
        <node concept="16NEbR" id="3yuK3TkZVy2" role="16NEbj">
          <property role="TrG5h" value="interact" />
        </node>
        <node concept="16Ny3_" id="3yuK3TkZWqi" role="16NEbj">
          <property role="16N0M8" value="To see office enviroment, manually control the actuators, set office parameters and for mantainance purposes" />
          <ref role="16Ny3F" node="3yuK3TkZVDZ" resolve="hmi" />
        </node>
        <node concept="16Ny3_" id="3yuK3TkZWqj" role="16NEbj">
          <property role="16N0M8" value="To see office enviroment, manually control the actuators, see malfunctions, set office parameters and for mantainance purposes" />
          <ref role="16Ny3F" node="3yuK3TkZW3l" resolve="ui" />
        </node>
        <node concept="16Ny3_" id="3yuK3TkZWq_" role="16NEbj">
          <property role="16N0M8" value="For mantainance purposes" />
          <ref role="16Ny3F" node="3yuK3TkZVzx" resolve="heater" />
        </node>
        <node concept="16Ny3_" id="3yuK3TkZWqL" role="16NEbj">
          <property role="16N0M8" value="For mantainance purposes" />
          <ref role="16Ny3F" node="3yuK3TkZV$q" resolve="lights" />
        </node>
        <node concept="16Ny3_" id="3yuK3TkZWqY" role="16NEbj">
          <property role="16N0M8" value="For mantainance purposes" />
          <ref role="16Ny3F" node="3yuK3TkZV$T" resolve="blinds" />
        </node>
        <node concept="16Ny3_" id="3yuK3TkZWrd" role="16NEbj">
          <property role="16N0M8" value="For mantainance purposes" />
          <ref role="16Ny3F" node="3yuK3TkZVI6" resolve="tempSensor" />
        </node>
        <node concept="16Ny3_" id="3yuK3TkZWru" role="16NEbj">
          <property role="16N0M8" value="For mantainance purposes" />
          <ref role="16Ny3F" node="3yuK3TkZVLm" resolve="amblightSensor" />
        </node>
        <node concept="16Ny3_" id="3yuK3TkZWrM" role="16NEbj">
          <property role="16N0M8" value="For mantainance purposes" />
          <ref role="16Ny3F" node="3yuK3TkZVy_" resolve="controlUnit" />
        </node>
      </node>
    </node>
    <node concept="OjmMv" id="3yuK3TkZT3i" role="tLAhV">
      <node concept="19SGf9" id="3yuK3TkZT3j" role="OjmMu">
        <node concept="19SUe$" id="3yuK3TkZT3k" role="19SJt6" />
      </node>
    </node>
    <node concept="2RsZnQ" id="3yuK3TkZT3l" role="2RsZnW" />
    <node concept="3GEVxB" id="3yuK3TkZWpR" role="1BwUYK">
      <ref role="3GEb4d" node="3yuK3TkZT14" resolve="Components" />
    </node>
    <node concept="3GEVxB" id="3yuK3TkZWpW" role="1BwUYK">
      <ref role="3GEb4d" node="3yuK3TkZPU$" resolve="Requirements" />
    </node>
  </node>
  <node concept="3fbPIq" id="3yuK3TkZT5u">
    <property role="TrG5h" value="Hazards" />
    <ref role="G9hjw" node="3yuK3TkZPUD" resolve="DefaultDocConfig" />
    <node concept="OjmMv" id="3yuK3TkZT5v" role="tLAhV">
      <node concept="19SGf9" id="3yuK3TkZT5w" role="OjmMu">
        <node concept="19SUe$" id="3yuK3TkZT5x" role="19SJt6" />
      </node>
    </node>
    <node concept="2RsZnQ" id="3yuK3TkZT5y" role="2RsZnW" />
    <node concept="3fbQ3u" id="3yuK3TkZU9K" role="3fbPIo">
      <property role="2DRQuN" value="1672949746398" />
      <property role="2DXwbs" value="rijo" />
      <property role="1ylvJX" value="Safety Hazards" />
      <property role="TrG5h" value="safetyHazard" />
      <node concept="GmGrk" id="3yuK3TkZU9M" role="GmGcz">
        <node concept="1_0LV8" id="3yuK3TkZU9N" role="1_0VJ0">
          <node concept="19SGf9" id="3yuK3TkZU9O" role="1_0LWR">
            <node concept="19SUe$" id="3yuK3TkZUaN" role="19SJt6">
              <property role="19SUeA" value="Definition of hazards that may cause damage to the " />
            </node>
            <node concept="2oIDSw" id="3yuK3TkZW97" role="19SJt6">
              <ref role="2wPqOu" node="3yuK3TkZTrD" resolve="user" />
            </node>
            <node concept="19SUe$" id="3yuK3TkZW98" role="19SJt6">
              <property role="19SUeA" value="." />
            </node>
          </node>
        </node>
      </node>
      <node concept="22Mrfp" id="3yuK3TkZVt7" role="22Mr8z" />
      <node concept="3fbQ3u" id="3yuK3TkZUIN" role="3fbPAY">
        <property role="2DRQuN" value="1672949746398" />
        <property role="2DXwbs" value="rijo" />
        <property role="1ylvJX" value="Fire Hazards" />
        <property role="TrG5h" value="fireHazard" />
        <node concept="GmGrk" id="3yuK3TkZUIO" role="GmGcz">
          <node concept="1_0LV8" id="3yuK3TkZUIP" role="1_0VJ0">
            <node concept="19SGf9" id="3yuK3TkZUIQ" role="1_0LWR">
              <node concept="19SUe$" id="3yuK3TkZUIR" role="19SJt6">
                <property role="19SUeA" value="The room or a componente of the system is on fire.&#10;Not addressed in the implementation of the system." />
              </node>
            </node>
          </node>
        </node>
        <node concept="22Mrfp" id="3yuK3TkZUIS" role="22Mr8z" />
      </node>
      <node concept="3fbQ3u" id="3yuK3TkZUN9" role="3fbPAY">
        <property role="2DRQuN" value="1672949746398" />
        <property role="2DXwbs" value="rijo" />
        <property role="1ylvJX" value="Flood Hazards" />
        <property role="TrG5h" value="floodHazard" />
        <node concept="GmGrk" id="3yuK3TkZUNa" role="GmGcz">
          <node concept="1_0LV8" id="3yuK3TkZUNb" role="1_0VJ0">
            <node concept="19SGf9" id="3yuK3TkZUNc" role="1_0LWR">
              <node concept="19SUe$" id="3yuK3TkZUNd" role="19SJt6">
                <property role="19SUeA" value="The room may be flooded.&#10;Not addressed in the implementation of the system." />
              </node>
            </node>
          </node>
        </node>
        <node concept="22Mrfp" id="3yuK3TkZUNe" role="22Mr8z" />
      </node>
      <node concept="3fbQ3u" id="3yuK3TkZUNr" role="3fbPAY">
        <property role="2DRQuN" value="1672949746398" />
        <property role="2DXwbs" value="rijo" />
        <property role="1ylvJX" value="Excess Humidity Hazards" />
        <property role="TrG5h" value="humidityHazard" />
        <node concept="GmGrk" id="3yuK3TkZUNs" role="GmGcz">
          <node concept="1_0LV8" id="3yuK3TkZUNt" role="1_0VJ0">
            <node concept="19SGf9" id="3yuK3TkZUNu" role="1_0LWR">
              <node concept="19SUe$" id="3yuK3TkZUNv" role="19SJt6">
                <property role="19SUeA" value="The room may have excess levels of humidity.&#10;Not addressed in the implementation of the system." />
              </node>
            </node>
          </node>
        </node>
        <node concept="22Mrfp" id="3yuK3TkZUNw" role="22Mr8z" />
      </node>
      <node concept="3fbQ3u" id="3yuK3TkZUNN" role="3fbPAY">
        <property role="2DRQuN" value="1672949746398" />
        <property role="2DXwbs" value="rijo" />
        <property role="1ylvJX" value="Earthquake Hazards" />
        <property role="TrG5h" value="earthquakeHazard" />
        <node concept="GmGrk" id="3yuK3TkZUNO" role="GmGcz">
          <node concept="1_0LV8" id="3yuK3TkZUNP" role="1_0VJ0">
            <node concept="19SGf9" id="3yuK3TkZUNQ" role="1_0LWR">
              <node concept="19SUe$" id="3yuK3TkZUNR" role="19SJt6">
                <property role="19SUeA" value="There may be an earthquake in the area.&#10;Not addressed in the implementation of the system." />
              </node>
            </node>
          </node>
        </node>
        <node concept="22Mrfp" id="3yuK3TkZUNS" role="22Mr8z" />
      </node>
      <node concept="3fbQ3u" id="3yuK3TkZUOh" role="3fbPAY">
        <property role="2DRQuN" value="1672949746398" />
        <property role="2DXwbs" value="rijo" />
        <property role="1ylvJX" value="Short Circuit Hazards" />
        <property role="TrG5h" value="ccHazard" />
        <node concept="GmGrk" id="3yuK3TkZUOi" role="GmGcz">
          <node concept="1_0LV8" id="3yuK3TkZUOj" role="1_0VJ0">
            <node concept="19SGf9" id="3yuK3TkZUOk" role="1_0LWR">
              <node concept="19SUe$" id="3yuK3TkZUOl" role="19SJt6">
                <property role="19SUeA" value="There may be a short circuit in any component.&#10;Not addressed in the implementation of the system." />
              </node>
            </node>
          </node>
        </node>
        <node concept="22Mrfp" id="3yuK3TkZUOm" role="22Mr8z" />
      </node>
      <node concept="3fbQ3u" id="3yuK3TkZUOP" role="3fbPAY">
        <property role="2DRQuN" value="1672949746398" />
        <property role="2DXwbs" value="rijo" />
        <property role="1ylvJX" value="Eletrical Shock Hazards" />
        <property role="TrG5h" value="shockHazard" />
        <node concept="GmGrk" id="3yuK3TkZUOQ" role="GmGcz">
          <node concept="1_0LV8" id="3yuK3TkZUOR" role="1_0VJ0">
            <node concept="19SGf9" id="3yuK3TkZUOS" role="1_0LWR">
              <node concept="19SUe$" id="3yuK3TkZUOT" role="19SJt6">
                <property role="19SUeA" value="The user may get eletrical shocked by any device.&#10;Not addressed in the implementation of the system." />
              </node>
            </node>
          </node>
        </node>
        <node concept="22Mrfp" id="3yuK3TkZUOU" role="22Mr8z" />
      </node>
      <node concept="3fbQ3u" id="3yuK3TkZUPv" role="3fbPAY">
        <property role="2DRQuN" value="1672949746398" />
        <property role="2DXwbs" value="rijo" />
        <property role="1ylvJX" value="Closing blinds Hazards" />
        <property role="TrG5h" value="closingHazard" />
        <node concept="GmGrk" id="3yuK3TkZUPw" role="GmGcz">
          <node concept="1_0LV8" id="3yuK3TkZUPx" role="1_0VJ0">
            <node concept="19SGf9" id="3yuK3TkZUPy" role="1_0LWR">
              <node concept="19SUe$" id="3yuK3TkZUPz" role="19SJt6">
                <property role="19SUeA" value="When a person gets stuck bellow the blinds.&#10;Not addressed in the implementation of the system" />
              </node>
            </node>
          </node>
        </node>
        <node concept="22Mrfp" id="3yuK3TkZUP$" role="22Mr8z" />
      </node>
      <node concept="3fbQ3u" id="3yuK3TkZUQf" role="3fbPAY">
        <property role="2DRQuN" value="1672949746398" />
        <property role="2DXwbs" value="rijo" />
        <property role="1ylvJX" value="Burn Hazards" />
        <property role="TrG5h" value="burnHazard" />
        <node concept="GmGrk" id="3yuK3TkZUQg" role="GmGcz">
          <node concept="1_0LV8" id="3yuK3TkZUQh" role="1_0VJ0">
            <node concept="19SGf9" id="3yuK3TkZUQi" role="1_0LWR">
              <node concept="19SUe$" id="3yuK3TkZUQj" role="19SJt6">
                <property role="19SUeA" value="When a person is burnt on the heater.&#10;Not addressed in the implementation of the system" />
              </node>
            </node>
          </node>
        </node>
        <node concept="22Mrfp" id="3yuK3TkZUQk" role="22Mr8z" />
      </node>
      <node concept="3fbQ3u" id="3yuK3TkZVrA" role="3fbPAY">
        <property role="2DRQuN" value="1672949746398" />
        <property role="2DXwbs" value="rijo" />
        <property role="1ylvJX" value="Broken window Hazards" />
        <property role="TrG5h" value="brokenWindoeHazard" />
        <node concept="GmGrk" id="3yuK3TkZVrB" role="GmGcz">
          <node concept="1_0LV8" id="3yuK3TkZVrC" role="1_0VJ0">
            <node concept="19SGf9" id="3yuK3TkZVrD" role="1_0LWR">
              <node concept="19SUe$" id="3yuK3TkZVrE" role="19SJt6">
                <property role="19SUeA" value="The office window may be broken.&#10;Not addressed in the implementation of the system" />
              </node>
            </node>
          </node>
        </node>
        <node concept="22Mrfp" id="3yuK3TkZVrF" role="22Mr8z" />
      </node>
    </node>
    <node concept="3fbQ3u" id="3yuK3TkZUaj" role="3fbPIo">
      <property role="2DRQuN" value="1672949746398" />
      <property role="2DXwbs" value="rijo" />
      <property role="1ylvJX" value="Components Hazards" />
      <property role="TrG5h" value="compHazard" />
      <node concept="GmGrk" id="3yuK3TkZUak" role="GmGcz">
        <node concept="1_0LV8" id="3yuK3TkZUal" role="1_0VJ0">
          <node concept="19SGf9" id="3yuK3TkZUam" role="1_0LWR">
            <node concept="19SUe$" id="3yuK3TkZUan" role="19SJt6">
              <property role="19SUeA" value="Definition of hazards related to the components." />
            </node>
          </node>
        </node>
      </node>
      <node concept="22Mrfp" id="3yuK3TkZUao" role="22Mr8z" />
      <node concept="3fbQ3u" id="3yuK3TkZUbh" role="3fbPAY">
        <property role="2DRQuN" value="1672949746398" />
        <property role="2DXwbs" value="rijo" />
        <property role="1ylvJX" value="Sensors Hazards" />
        <property role="TrG5h" value="sensorHazard" />
        <node concept="GmGrk" id="3yuK3TkZUbi" role="GmGcz">
          <node concept="1_0LV8" id="3yuK3TkZUbj" role="1_0VJ0">
            <node concept="19SGf9" id="3yuK3TkZUbk" role="1_0LWR">
              <node concept="19SUe$" id="3yuK3TkZUbl" role="19SJt6">
                <property role="19SUeA" value="Hazards related to the sensors." />
              </node>
            </node>
          </node>
        </node>
        <node concept="22Mrfp" id="3yuK3TkZUbm" role="22Mr8z" />
        <node concept="3fbQ3u" id="3yuK3TkZUcT" role="3fbPAY">
          <property role="2DRQuN" value="1672949746398" />
          <property role="2DXwbs" value="rijo" />
          <property role="1ylvJX" value="Temperature Sensor Hazard" />
          <property role="TrG5h" value="tempSensorHazard" />
          <node concept="GmGrk" id="3yuK3TkZUcU" role="GmGcz">
            <node concept="1_0LV8" id="3yuK3TkZUcV" role="1_0VJ0">
              <node concept="19SGf9" id="3yuK3TkZUcW" role="1_0LWR">
                <node concept="19SUe$" id="3yuK3TkZUcX" role="19SJt6">
                  <property role="19SUeA" value="Temperature sensor/s " />
                </node>
                <node concept="2oIDSw" id="3yuK3TkZW9d" role="19SJt6">
                  <ref role="2wPqOu" node="3yuK3TkZVI0" resolve="tempSensor" />
                </node>
                <node concept="19SUe$" id="3yuK3TkZW9c" role="19SJt6">
                  <property role="19SUeA" value=" has a malfunction&#10;Mitigation: Report the malfunction to the control unit and maintenance departement " />
                </node>
                <node concept="2oIDSw" id="3yuK3TkZW9q" role="19SJt6">
                  <ref role="2wPqOu" node="3yuK3TkZTrY" resolve="maintenanceDep" />
                </node>
                <node concept="19SUe$" id="3yuK3TkZW9r" role="19SJt6">
                  <property role="19SUeA" value="." />
                </node>
              </node>
            </node>
          </node>
          <node concept="22Mrfp" id="3yuK3TkZUcY" role="22Mr8z" />
        </node>
        <node concept="3fbQ3u" id="3yuK3TkZUfB" role="3fbPAY">
          <property role="2DRQuN" value="1672949746398" />
          <property role="2DXwbs" value="rijo" />
          <property role="1ylvJX" value="Inside Ambient Light Sensor Hazard" />
          <property role="TrG5h" value="insideLightSensorHazard" />
          <node concept="GmGrk" id="3yuK3TkZUfC" role="GmGcz">
            <node concept="1_0LV8" id="3yuK3TkZUfD" role="1_0VJ0">
              <node concept="19SGf9" id="3yuK3TkZUfE" role="1_0LWR">
                <node concept="19SUe$" id="3yuK3TkZUfF" role="19SJt6">
                  <property role="19SUeA" value="Ambient Light sensor/s " />
                </node>
                <node concept="2oIDSw" id="3yuK3TkZWaO" role="19SJt6">
                  <ref role="2wPqOu" node="3yuK3TkZVLg" resolve="amblightSensor" />
                </node>
                <node concept="19SUe$" id="3yuK3TkZWaP" role="19SJt6">
                  <property role="19SUeA" value=" inside the office has a malfunction.&#10;Mitigation: Report the malfunction to the control unit and maintenance departement " />
                </node>
                <node concept="2oIDSw" id="3yuK3TkZWba" role="19SJt6">
                  <ref role="2wPqOu" node="3yuK3TkZTrY" resolve="maintenanceDep" />
                </node>
                <node concept="19SUe$" id="3yuK3TkZWb9" role="19SJt6">
                  <property role="19SUeA" value="." />
                </node>
              </node>
            </node>
          </node>
          <node concept="22Mrfp" id="3yuK3TkZUfG" role="22Mr8z" />
        </node>
        <node concept="3fbQ3u" id="3yuK3TkZUfY" role="3fbPAY">
          <property role="2DRQuN" value="1672949746398" />
          <property role="2DXwbs" value="rijo" />
          <property role="1ylvJX" value="Outside Ambient Light Sensor Hazard" />
          <property role="TrG5h" value="outsidelightSensorHazard" />
          <node concept="GmGrk" id="3yuK3TkZUfZ" role="GmGcz">
            <node concept="1_0LV8" id="3yuK3TkZUg0" role="1_0VJ0">
              <node concept="19SGf9" id="3yuK3TkZUg1" role="1_0LWR">
                <node concept="19SUe$" id="3yuK3TkZUg2" role="19SJt6">
                  <property role="19SUeA" value="Ambient Light sensor/s " />
                </node>
                <node concept="2oIDSw" id="3yuK3TkZWb4" role="19SJt6">
                  <ref role="2wPqOu" node="3yuK3TkZVLg" resolve="amblightSensor" />
                </node>
                <node concept="19SUe$" id="3yuK3TkZWb5" role="19SJt6">
                  <property role="19SUeA" value=" outside the office has a malfunction.&#10;Mitigation: Report the malfunction to the control unit and maintenance departement " />
                </node>
                <node concept="2oIDSw" id="3yuK3TkZWbh" role="19SJt6">
                  <ref role="2wPqOu" node="3yuK3TkZTrY" resolve="maintenanceDep" />
                </node>
                <node concept="19SUe$" id="3yuK3TkZWbg" role="19SJt6">
                  <property role="19SUeA" value="." />
                </node>
              </node>
            </node>
          </node>
          <node concept="22Mrfp" id="3yuK3TkZUg3" role="22Mr8z" />
        </node>
        <node concept="3fbQ3u" id="3yuK3TkZUgw" role="3fbPAY">
          <property role="2DRQuN" value="1672949746398" />
          <property role="2DXwbs" value="rijo" />
          <property role="1ylvJX" value="Blinds position contact switch Hazard" />
          <property role="TrG5h" value="blindSensorHazard" />
          <node concept="GmGrk" id="3yuK3TkZUgx" role="GmGcz">
            <node concept="1_0LV8" id="3yuK3TkZUgy" role="1_0VJ0">
              <node concept="19SGf9" id="3yuK3TkZUgz" role="1_0LWR">
                <node concept="19SUe$" id="3yuK3TkZUg$" role="19SJt6">
                  <property role="19SUeA" value="Blinds position contact switch " />
                </node>
                <node concept="2oIDSw" id="3yuK3TkZWc9" role="19SJt6">
                  <ref role="2wPqOu" node="3yuK3TkZVUI" resolve="blindsPosition" />
                </node>
                <node concept="19SUe$" id="3yuK3TkZWca" role="19SJt6">
                  <property role="19SUeA" value=" has a malfunction.&#10;Mitigation: Report the malfunction to the control unit and maintenance departement " />
                </node>
                <node concept="2oIDSw" id="3yuK3TkZWbo" role="19SJt6">
                  <ref role="2wPqOu" node="3yuK3TkZTrY" resolve="maintenanceDep" />
                </node>
                <node concept="19SUe$" id="3yuK3TkZWbn" role="19SJt6">
                  <property role="19SUeA" value="." />
                </node>
              </node>
            </node>
          </node>
          <node concept="22Mrfp" id="3yuK3TkZUg_" role="22Mr8z" />
        </node>
        <node concept="3fbQ3u" id="3yuK3TkZUgZ" role="3fbPAY">
          <property role="2DRQuN" value="1672949746398" />
          <property role="2DXwbs" value="rijo" />
          <property role="1ylvJX" value="Window Security Sensor Hazard" />
          <property role="TrG5h" value="windowSecHazard" />
          <node concept="GmGrk" id="3yuK3TkZUh0" role="GmGcz">
            <node concept="1_0LV8" id="3yuK3TkZUh1" role="1_0VJ0">
              <node concept="19SGf9" id="3yuK3TkZUh2" role="1_0LWR">
                <node concept="19SUe$" id="3yuK3TkZUh3" role="19SJt6">
                  <property role="19SUeA" value="Windown security sensor " />
                </node>
                <node concept="2oIDSw" id="3yuK3TkZWcg" role="19SJt6">
                  <ref role="2wPqOu" node="3yuK3TkZVCF" resolve="blindsWindow" />
                </node>
                <node concept="19SUe$" id="3yuK3TkZWch" role="19SJt6">
                  <property role="19SUeA" value=" has a malfunction.&#10;Mitigation: Report the malfunction to the maintenance departement " />
                </node>
                <node concept="2oIDSw" id="3yuK3TkZWbt" role="19SJt6">
                  <ref role="2wPqOu" node="3yuK3TkZTrY" resolve="maintenanceDep" />
                </node>
                <node concept="19SUe$" id="3yuK3TkZWbs" role="19SJt6">
                  <property role="19SUeA" value="." />
                </node>
              </node>
            </node>
          </node>
          <node concept="22Mrfp" id="3yuK3TkZUh4" role="22Mr8z" />
        </node>
      </node>
      <node concept="3fbQ3u" id="3yuK3TkZVdO" role="3fbPAY">
        <property role="2DRQuN" value="1672949746398" />
        <property role="2DXwbs" value="rijo" />
        <property role="1ylvJX" value="Power Supply Hazards" />
        <property role="TrG5h" value="psuHazard" />
        <node concept="GmGrk" id="3yuK3TkZVdP" role="GmGcz">
          <node concept="1_0LV8" id="3yuK3TkZVdQ" role="1_0VJ0">
            <node concept="19SGf9" id="3yuK3TkZVdR" role="1_0LWR">
              <node concept="19SUe$" id="3yuK3TkZVdS" role="19SJt6">
                <property role="19SUeA" value="When there is no power supply in the system.&#10;Not addressed in the implementation of the system." />
              </node>
            </node>
          </node>
        </node>
        <node concept="22Mrfp" id="3yuK3TkZVdT" role="22Mr8z" />
      </node>
      <node concept="3fbQ3u" id="3yuK3TkZUcf" role="3fbPAY">
        <property role="2DRQuN" value="1672949746398" />
        <property role="2DXwbs" value="rijo" />
        <property role="1ylvJX" value="Actuators Hazards" />
        <property role="TrG5h" value="actuatorHazard" />
        <node concept="GmGrk" id="3yuK3TkZUcg" role="GmGcz">
          <node concept="1_0LV8" id="3yuK3TkZUch" role="1_0VJ0">
            <node concept="19SGf9" id="3yuK3TkZUci" role="1_0LWR">
              <node concept="19SUe$" id="3yuK3TkZUcj" role="19SJt6">
                <property role="19SUeA" value="Hazards related to the actuators" />
              </node>
            </node>
          </node>
        </node>
        <node concept="22Mrfp" id="3yuK3TkZUck" role="22Mr8z" />
        <node concept="3fbQ3u" id="3yuK3TkZUdP" role="3fbPAY">
          <property role="2DRQuN" value="1672949746398" />
          <property role="2DXwbs" value="rijo" />
          <property role="1ylvJX" value="Smart Heater Hazard" />
          <property role="TrG5h" value="heaterHazard" />
          <node concept="GmGrk" id="3yuK3TkZUdQ" role="GmGcz">
            <node concept="1_0LV8" id="3yuK3TkZUdR" role="1_0VJ0">
              <node concept="19SGf9" id="3yuK3TkZUdS" role="1_0LWR">
                <node concept="19SUe$" id="3yuK3TkZUdT" role="19SJt6">
                  <property role="19SUeA" value="Smart heater " />
                </node>
                <node concept="2oIDSw" id="3yuK3TkZWcn" role="19SJt6">
                  <ref role="2wPqOu" node="3yuK3TkZVyC" resolve="heater" />
                </node>
                <node concept="19SUe$" id="3yuK3TkZWco" role="19SJt6">
                  <property role="19SUeA" value=" has a malfunction.&#10;Mitigation: Report the malfunction to the control unit and maintenance departement " />
                </node>
                <node concept="2oIDSw" id="3yuK3TkZWby" role="19SJt6">
                  <ref role="2wPqOu" node="3yuK3TkZTrY" resolve="maintenanceDep" />
                </node>
                <node concept="19SUe$" id="3yuK3TkZWbx" role="19SJt6">
                  <property role="19SUeA" value="." />
                </node>
              </node>
            </node>
          </node>
          <node concept="22Mrfp" id="3yuK3TkZUdU" role="22Mr8z" />
        </node>
        <node concept="3fbQ3u" id="3yuK3TkZUeX" role="3fbPAY">
          <property role="2DRQuN" value="1672949746398" />
          <property role="2DXwbs" value="rijo" />
          <property role="1ylvJX" value="Smart Lights Hazard" />
          <property role="TrG5h" value="lightsHazard" />
          <node concept="GmGrk" id="3yuK3TkZUeY" role="GmGcz">
            <node concept="1_0LV8" id="3yuK3TkZUeZ" role="1_0VJ0">
              <node concept="19SGf9" id="3yuK3TkZUf0" role="1_0LWR">
                <node concept="19SUe$" id="3yuK3TkZUf1" role="19SJt6">
                  <property role="19SUeA" value="Smart lights " />
                </node>
                <node concept="2oIDSw" id="3yuK3TkZWcu" role="19SJt6">
                  <ref role="2wPqOu" node="3yuK3TkZV$k" resolve="lights" />
                </node>
                <node concept="19SUe$" id="3yuK3TkZWcv" role="19SJt6">
                  <property role="19SUeA" value=" has malfunction.&#10;Mitigation: Report the malfunction to the control unit and maintenance departement " />
                </node>
                <node concept="2oIDSw" id="3yuK3TkZWbB" role="19SJt6">
                  <ref role="2wPqOu" node="3yuK3TkZTrY" resolve="maintenanceDep" />
                </node>
                <node concept="19SUe$" id="3yuK3TkZWbA" role="19SJt6">
                  <property role="19SUeA" value="." />
                </node>
              </node>
            </node>
          </node>
          <node concept="22Mrfp" id="3yuK3TkZUf2" role="22Mr8z" />
        </node>
        <node concept="3fbQ3u" id="3yuK3TkZUff" role="3fbPAY">
          <property role="2DRQuN" value="1672949746398" />
          <property role="2DXwbs" value="rijo" />
          <property role="1ylvJX" value="Smart Blinds Hazard" />
          <property role="TrG5h" value="blindsHazard" />
          <node concept="GmGrk" id="3yuK3TkZUfg" role="GmGcz">
            <node concept="1_0LV8" id="3yuK3TkZUfh" role="1_0VJ0">
              <node concept="19SGf9" id="3yuK3TkZUfi" role="1_0LWR">
                <node concept="19SUe$" id="3yuK3TkZUfj" role="19SJt6">
                  <property role="19SUeA" value="Smart blinds " />
                </node>
                <node concept="2oIDSw" id="3yuK3TkZWcA" role="19SJt6">
                  <ref role="2wPqOu" node="3yuK3TkZV$N" resolve="blinds" />
                </node>
                <node concept="19SUe$" id="3yuK3TkZWc_" role="19SJt6">
                  <property role="19SUeA" value=" has malfunction.&#10;Mitigation: Report the malfunction to the control unit and maintenance departement " />
                </node>
                <node concept="2oIDSw" id="3yuK3TkZWbG" role="19SJt6">
                  <ref role="2wPqOu" node="3yuK3TkZTrY" resolve="maintenanceDep" />
                </node>
                <node concept="19SUe$" id="3yuK3TkZWbF" role="19SJt6">
                  <property role="19SUeA" value="." />
                </node>
              </node>
            </node>
          </node>
          <node concept="22Mrfp" id="3yuK3TkZUfk" role="22Mr8z" />
        </node>
        <node concept="3fbQ3u" id="3yuK3TkZWd_" role="3fbPAY">
          <property role="2DRQuN" value="1672949746398" />
          <property role="2DXwbs" value="rijo" />
          <property role="1ylvJX" value="Smart Blinds Motor Hazard" />
          <property role="TrG5h" value="blindsMotorHazard" />
          <node concept="GmGrk" id="3yuK3TkZWdA" role="GmGcz">
            <node concept="1_0LV8" id="3yuK3TkZWdB" role="1_0VJ0">
              <node concept="19SGf9" id="3yuK3TkZWdC" role="1_0LWR">
                <node concept="19SUe$" id="3yuK3TkZWdD" role="19SJt6">
                  <property role="19SUeA" value="Smart blinds motor " />
                </node>
                <node concept="2oIDSw" id="3yuK3TkZWdE" role="19SJt6">
                  <ref role="2wPqOu" node="3yuK3TkZVCg" resolve="blindsMotor" />
                </node>
                <node concept="19SUe$" id="3yuK3TkZWdF" role="19SJt6">
                  <property role="19SUeA" value=" has malfunction.&#10;Mitigation: Report the malfunction to the control unit and maintenance departement " />
                </node>
                <node concept="2oIDSw" id="3yuK3TkZWdG" role="19SJt6">
                  <ref role="2wPqOu" node="3yuK3TkZTrY" resolve="maintenanceDep" />
                </node>
                <node concept="19SUe$" id="3yuK3TkZWdH" role="19SJt6">
                  <property role="19SUeA" value="." />
                </node>
              </node>
            </node>
          </node>
          <node concept="22Mrfp" id="3yuK3TkZWdI" role="22Mr8z" />
        </node>
        <node concept="3fbQ3u" id="3yuK3TkZWen" role="3fbPAY">
          <property role="2DRQuN" value="1672949746398" />
          <property role="2DXwbs" value="rijo" />
          <property role="1ylvJX" value="Smart Blinds Motor Controller Hazard" />
          <property role="TrG5h" value="blindsMotorControllerHazard" />
          <node concept="GmGrk" id="3yuK3TkZWeo" role="GmGcz">
            <node concept="1_0LV8" id="3yuK3TkZWep" role="1_0VJ0">
              <node concept="19SGf9" id="3yuK3TkZWeq" role="1_0LWR">
                <node concept="19SUe$" id="3yuK3TkZWer" role="19SJt6">
                  <property role="19SUeA" value="Smart blinds motor controller " />
                </node>
                <node concept="2oIDSw" id="3yuK3TkZWes" role="19SJt6">
                  <ref role="2wPqOu" node="3yuK3TkZVVA" resolve="blindsMotorController" />
                </node>
                <node concept="19SUe$" id="3yuK3TkZWet" role="19SJt6">
                  <property role="19SUeA" value=" has malfunction.&#10;Mitigation: Report the malfunction to the control unit and maintenance departement " />
                </node>
                <node concept="2oIDSw" id="3yuK3TkZWeu" role="19SJt6">
                  <ref role="2wPqOu" node="3yuK3TkZTrY" resolve="maintenanceDep" />
                </node>
                <node concept="19SUe$" id="3yuK3TkZWev" role="19SJt6">
                  <property role="19SUeA" value="." />
                </node>
              </node>
            </node>
          </node>
          <node concept="22Mrfp" id="3yuK3TkZWew" role="22Mr8z" />
        </node>
      </node>
      <node concept="3fbQ3u" id="3yuK3TkZUcx" role="3fbPAY">
        <property role="2DRQuN" value="1672949746398" />
        <property role="2DXwbs" value="rijo" />
        <property role="1ylvJX" value="Contoler Unit Hazards" />
        <property role="TrG5h" value="controllerHazard" />
        <node concept="GmGrk" id="3yuK3TkZUcy" role="GmGcz">
          <node concept="1_0LV8" id="3yuK3TkZUcz" role="1_0VJ0">
            <node concept="19SGf9" id="3yuK3TkZUc$" role="1_0LWR">
              <node concept="19SUe$" id="3yuK3TkZUc_" role="19SJt6">
                <property role="19SUeA" value="Control Unit " />
              </node>
              <node concept="2oIDSw" id="3yuK3TkZWcI" role="19SJt6">
                <ref role="2wPqOu" node="3yuK3TkZVy5" resolve="controlUnit" />
              </node>
              <node concept="19SUe$" id="3yuK3TkZWcJ" role="19SJt6">
                <property role="19SUeA" value=" has a malfunction" />
              </node>
            </node>
          </node>
        </node>
        <node concept="22Mrfp" id="3yuK3TkZUcA" role="22Mr8z" />
        <node concept="3fbQ3u" id="3yuK3TkZUhB" role="3fbPAY">
          <property role="2DRQuN" value="1672949746398" />
          <property role="2DXwbs" value="rijo" />
          <property role="1ylvJX" value="Sensor Communication Hazards" />
          <property role="TrG5h" value="sensorComHazard" />
          <node concept="GmGrk" id="3yuK3TkZUhC" role="GmGcz">
            <node concept="1_0LV8" id="3yuK3TkZUhD" role="1_0VJ0">
              <node concept="19SGf9" id="3yuK3TkZUhE" role="1_0LWR">
                <node concept="19SUe$" id="3yuK3TkZUhF" role="19SJt6">
                  <property role="19SUeA" value="Control unit " />
                </node>
                <node concept="2oIDSw" id="3yuK3TkZWcO" role="19SJt6">
                  <ref role="2wPqOu" node="3yuK3TkZVy5" resolve="controlUnit" />
                </node>
                <node concept="19SUe$" id="3yuK3TkZWcN" role="19SJt6">
                  <property role="19SUeA" value=" can not communicate with sensors.&#10;Mitigation: Report the malfunction to the control unit and maintenance departement " />
                </node>
                <node concept="2oIDSw" id="3yuK3TkZWbL" role="19SJt6">
                  <ref role="2wPqOu" node="3yuK3TkZTrY" resolve="maintenanceDep" />
                </node>
                <node concept="19SUe$" id="3yuK3TkZWbK" role="19SJt6">
                  <property role="19SUeA" value="." />
                </node>
              </node>
            </node>
          </node>
          <node concept="22Mrfp" id="3yuK3TkZUhG" role="22Mr8z" />
        </node>
        <node concept="3fbQ3u" id="3yuK3TkZUiP" role="3fbPAY">
          <property role="2DRQuN" value="1672949746398" />
          <property role="2DXwbs" value="rijo" />
          <property role="1ylvJX" value="Actuators Communication Hazards" />
          <property role="TrG5h" value="actuatorComHazard" />
          <node concept="GmGrk" id="3yuK3TkZUiQ" role="GmGcz">
            <node concept="1_0LV8" id="3yuK3TkZUiR" role="1_0VJ0">
              <node concept="19SGf9" id="3yuK3TkZUiS" role="1_0LWR">
                <node concept="19SUe$" id="3yuK3TkZUiT" role="19SJt6">
                  <property role="19SUeA" value="Control unit " />
                </node>
                <node concept="2oIDSw" id="3yuK3TkZWcW" role="19SJt6">
                  <ref role="2wPqOu" node="3yuK3TkZVy5" resolve="controlUnit" />
                </node>
                <node concept="19SUe$" id="3yuK3TkZWcX" role="19SJt6">
                  <property role="19SUeA" value=" can not communicate with actuators.&#10;Mitigation: Report the malfunction to the control unit and maintenance departement " />
                </node>
                <node concept="2oIDSw" id="3yuK3TkZWbQ" role="19SJt6">
                  <ref role="2wPqOu" node="3yuK3TkZTrY" resolve="maintenanceDep" />
                </node>
                <node concept="19SUe$" id="3yuK3TkZWbP" role="19SJt6">
                  <property role="19SUeA" value="." />
                </node>
              </node>
            </node>
          </node>
          <node concept="22Mrfp" id="3yuK3TkZUiU" role="22Mr8z" />
        </node>
        <node concept="3fbQ3u" id="3yuK3TkZUni" role="3fbPAY">
          <property role="2DRQuN" value="1672949746398" />
          <property role="2DXwbs" value="rijo" />
          <property role="1ylvJX" value="HMI Hazards" />
          <property role="TrG5h" value="hmiHazard" />
          <node concept="GmGrk" id="3yuK3TkZUnj" role="GmGcz">
            <node concept="1_0LV8" id="3yuK3TkZUof" role="1_0VJ0">
              <node concept="19SGf9" id="3yuK3TkZUog" role="1_0LWR">
                <node concept="19SUe$" id="3yuK3TkZUoh" role="19SJt6">
                  <property role="19SUeA" value="HMI " />
                </node>
                <node concept="2oIDSw" id="3yuK3TkZWd5" role="19SJt6">
                  <ref role="2wPqOu" node="3yuK3TkZVDT" resolve="hmi" />
                </node>
                <node concept="19SUe$" id="3yuK3TkZWd6" role="19SJt6">
                  <property role="19SUeA" value=" has a malfunction.&#10;Not addressed in the implementation of the system." />
                </node>
              </node>
            </node>
          </node>
          <node concept="22Mrfp" id="3yuK3TkZUnn" role="22Mr8z" />
          <node concept="3fbQ3u" id="3yuK3TkZUmU" role="3fbPAY">
            <property role="2DRQuN" value="1672949746398" />
            <property role="2DXwbs" value="rijo" />
            <property role="1ylvJX" value="HMI Communication Hazards" />
            <property role="TrG5h" value="hmiCOMHazard" />
            <node concept="GmGrk" id="3yuK3TkZUmV" role="GmGcz">
              <node concept="1_0LV8" id="3yuK3TkZUmW" role="1_0VJ0">
                <node concept="19SGf9" id="3yuK3TkZUmX" role="1_0LWR">
                  <node concept="19SUe$" id="3yuK3TkZUmY" role="19SJt6">
                    <property role="19SUeA" value="Control unit can not communicate with HMI.&#10;Not addressed in the implementation of the system." />
                  </node>
                </node>
              </node>
            </node>
            <node concept="22Mrfp" id="3yuK3TkZUmZ" role="22Mr8z" />
          </node>
        </node>
        <node concept="3fbQ3u" id="3yuK3TkZUom" role="3fbPAY">
          <property role="2DRQuN" value="1672949746398" />
          <property role="2DXwbs" value="rijo" />
          <property role="1ylvJX" value="Card Bay Hazards" />
          <property role="TrG5h" value="cardHazard" />
          <node concept="GmGrk" id="3yuK3TkZUon" role="GmGcz">
            <node concept="1_0LV8" id="3yuK3TkZUoo" role="1_0VJ0">
              <node concept="19SGf9" id="3yuK3TkZUop" role="1_0LWR">
                <node concept="19SUe$" id="3yuK3TkZUoq" role="19SJt6">
                  <property role="19SUeA" value="Card bay " />
                </node>
                <node concept="2oIDSw" id="3yuK3TkZWde" role="19SJt6">
                  <ref role="2wPqOu" node="3yuK3TkZVFq" resolve="cardBay" />
                </node>
                <node concept="19SUe$" id="3yuK3TkZWdf" role="19SJt6">
                  <property role="19SUeA" value=" has a malfunction.&#10;Mitigation: Report the malfunction to the control unit and maintenance departement " />
                </node>
                <node concept="2oIDSw" id="3yuK3TkZWbV" role="19SJt6">
                  <ref role="2wPqOu" node="3yuK3TkZTrY" resolve="maintenanceDep" />
                </node>
                <node concept="19SUe$" id="3yuK3TkZWbU" role="19SJt6">
                  <property role="19SUeA" value="." />
                </node>
              </node>
            </node>
          </node>
          <node concept="22Mrfp" id="3yuK3TkZUor" role="22Mr8z" />
        </node>
      </node>
      <node concept="3fbQ3u" id="3yuK3TkZUqF" role="3fbPAY">
        <property role="2DRQuN" value="1672949746398" />
        <property role="2DXwbs" value="rijo" />
        <property role="1ylvJX" value="Communication Hazards" />
        <property role="TrG5h" value="wirelessHazard" />
        <node concept="GmGrk" id="3yuK3TkZUqG" role="GmGcz">
          <node concept="1_0LV8" id="3yuK3TkZUqH" role="1_0VJ0">
            <node concept="19SGf9" id="3yuK3TkZUqI" role="1_0LWR">
              <node concept="19SUe$" id="3yuK3TkZUqJ" role="19SJt6">
                <property role="19SUeA" value="Control Unit " />
              </node>
              <node concept="2oIDSw" id="3yuK3TkZWdm" role="19SJt6">
                <ref role="2wPqOu" node="3yuK3TkZVy5" resolve="controlUnit" />
              </node>
              <node concept="19SUe$" id="3yuK3TkZWdl" role="19SJt6">
                <property role="19SUeA" value=" can not detected any available network.&#10;Mitigation: Talk to the maintenance departement " />
              </node>
              <node concept="2oIDSw" id="3yuK3TkZWc0" role="19SJt6">
                <ref role="2wPqOu" node="3yuK3TkZTrY" resolve="maintenanceDep" />
              </node>
              <node concept="19SUe$" id="3yuK3TkZWbZ" role="19SJt6">
                <property role="19SUeA" value="." />
              </node>
            </node>
          </node>
        </node>
        <node concept="22Mrfp" id="3yuK3TkZUqK" role="22Mr8z" />
        <node concept="3fbQ3u" id="3yuK3TkZUwX" role="3fbPAY">
          <property role="2DRQuN" value="1672949746398" />
          <property role="2DXwbs" value="rijo" />
          <property role="1ylvJX" value="Server Communication Hazards" />
          <property role="TrG5h" value="serverComHazard" />
          <node concept="GmGrk" id="3yuK3TkZUwY" role="GmGcz">
            <node concept="1_0LV8" id="3yuK3TkZUwZ" role="1_0VJ0">
              <node concept="19SGf9" id="3yuK3TkZUx0" role="1_0LWR">
                <node concept="19SUe$" id="3yuK3TkZUx1" role="19SJt6">
                  <property role="19SUeA" value="Control Unit " />
                </node>
                <node concept="2oIDSw" id="3yuK3TkZWdt" role="19SJt6">
                  <ref role="2wPqOu" node="3yuK3TkZVy5" resolve="controlUnit" />
                </node>
                <node concept="19SUe$" id="3yuK3TkZWds" role="19SJt6">
                  <property role="19SUeA" value=" can not bind to the server.&#10;Mitigation: Talk to the maintenance departement " />
                </node>
                <node concept="2oIDSw" id="3yuK3TkZWc5" role="19SJt6">
                  <ref role="2wPqOu" node="3yuK3TkZTrY" resolve="maintenanceDep" />
                </node>
                <node concept="19SUe$" id="3yuK3TkZWc4" role="19SJt6">
                  <property role="19SUeA" value="." />
                </node>
              </node>
            </node>
          </node>
          <node concept="22Mrfp" id="3yuK3TkZUx2" role="22Mr8z" />
        </node>
      </node>
    </node>
    <node concept="3fbQ3u" id="3yuK3TkZUaP" role="3fbPIo">
      <property role="2DRQuN" value="1672949746398" />
      <property role="2DXwbs" value="rijo" />
      <property role="1ylvJX" value="Security Hazards" />
      <property role="TrG5h" value="securityHazard" />
      <node concept="GmGrk" id="3yuK3TkZUaQ" role="GmGcz">
        <node concept="1_0LV8" id="3yuK3TkZUaR" role="1_0VJ0">
          <node concept="19SGf9" id="3yuK3TkZUaS" role="1_0LWR">
            <node concept="19SUe$" id="3yuK3TkZU9P" role="19SJt6">
              <property role="19SUeA" value="Definition of hazards related to Data security" />
            </node>
          </node>
        </node>
      </node>
      <node concept="22Mrfp" id="3yuK3TkZUaT" role="22Mr8z" />
      <node concept="3fbQ3u" id="3yuK3TkZVgI" role="3fbPAY">
        <property role="2DRQuN" value="1672949746398" />
        <property role="2DXwbs" value="rijo" />
        <property role="1ylvJX" value="DDoS Hazards" />
        <property role="TrG5h" value="ddosHazard" />
        <node concept="GmGrk" id="3yuK3TkZVgJ" role="GmGcz">
          <node concept="1_0LV8" id="3yuK3TkZVgK" role="1_0VJ0">
            <node concept="19SGf9" id="3yuK3TkZVgL" role="1_0LWR">
              <node concept="19SUe$" id="3yuK3TkZVsI" role="19SJt6">
                <property role="19SUeA" value="Traffic overwhelming attack to make service unavailable.&#10;Not addressed in the implementation of the system." />
              </node>
            </node>
          </node>
        </node>
        <node concept="22Mrfp" id="3yuK3TkZVgN" role="22Mr8z" />
      </node>
      <node concept="3fbQ3u" id="3yuK3TkZVmI" role="3fbPAY">
        <property role="2DRQuN" value="1672949746398" />
        <property role="2DXwbs" value="rijo" />
        <property role="1ylvJX" value="Firmware Hazards" />
        <property role="TrG5h" value="firmewareHazard" />
        <node concept="GmGrk" id="3yuK3TkZVmJ" role="GmGcz">
          <node concept="1_0LV8" id="3yuK3TkZVmK" role="1_0VJ0">
            <node concept="19SGf9" id="3yuK3TkZVmL" role="1_0LWR">
              <node concept="19SUe$" id="3yuK3TkZVt2" role="19SJt6">
                <property role="19SUeA" value="Firmware exploits&#10;Not addressed in the implementation of the system." />
              </node>
            </node>
          </node>
        </node>
        <node concept="22Mrfp" id="3yuK3TkZVmN" role="22Mr8z" />
      </node>
      <node concept="3fbQ3u" id="3yuK3TkZVn0" role="3fbPAY">
        <property role="2DRQuN" value="1672949746398" />
        <property role="2DXwbs" value="rijo" />
        <property role="1ylvJX" value="Man-in-the-middle Hazards" />
        <property role="TrG5h" value="manHazard" />
        <node concept="GmGrk" id="3yuK3TkZVn1" role="GmGcz">
          <node concept="1_0LV8" id="3yuK3TkZVn2" role="1_0VJ0">
            <node concept="19SGf9" id="3yuK3TkZVn3" role="1_0LWR">
              <node concept="19SUe$" id="3yuK3TkZVn4" role="19SJt6">
                <property role="19SUeA" value="Attack intercepting communication between parties.&#10;Not addressed in the implementation of the system." />
              </node>
            </node>
          </node>
        </node>
        <node concept="22Mrfp" id="3yuK3TkZVn5" role="22Mr8z" />
      </node>
      <node concept="3fbQ3u" id="3yuK3TkZVno" role="3fbPAY">
        <property role="2DRQuN" value="1672949746398" />
        <property role="2DXwbs" value="rijo" />
        <property role="1ylvJX" value="Lost package Hazards" />
        <property role="TrG5h" value="packageHazard" />
        <node concept="GmGrk" id="3yuK3TkZVnp" role="GmGcz">
          <node concept="1_0LV8" id="3yuK3TkZVnq" role="1_0VJ0">
            <node concept="19SGf9" id="3yuK3TkZVnr" role="1_0LWR">
              <node concept="19SUe$" id="3yuK3TkZVns" role="19SJt6">
                <property role="19SUeA" value="Data not received due to transmission failure.&#10;Not addressed in the implementation of the system." />
              </node>
            </node>
          </node>
        </node>
        <node concept="22Mrfp" id="3yuK3TkZVnt" role="22Mr8z" />
      </node>
      <node concept="3fbQ3u" id="3yuK3TkZVnQ" role="3fbPAY">
        <property role="2DRQuN" value="1672949746398" />
        <property role="2DXwbs" value="rijo" />
        <property role="1ylvJX" value="Phisical attacks Hazards" />
        <property role="TrG5h" value="pAttackHazard" />
        <node concept="GmGrk" id="3yuK3TkZVnR" role="GmGcz">
          <node concept="1_0LV8" id="3yuK3TkZVnS" role="1_0VJ0">
            <node concept="19SGf9" id="3yuK3TkZVnT" role="1_0LWR">
              <node concept="19SUe$" id="3yuK3TkZVnU" role="19SJt6">
                <property role="19SUeA" value="Physical tampering with the infrastructure.&#10;Not addressed in the implementation of the system." />
              </node>
            </node>
          </node>
        </node>
        <node concept="22Mrfp" id="3yuK3TkZVnV" role="22Mr8z" />
      </node>
      <node concept="3fbQ3u" id="3yuK3TkZVoq" role="3fbPAY">
        <property role="2DRQuN" value="1672949746398" />
        <property role="2DXwbs" value="rijo" />
        <property role="1ylvJX" value="Unauthorized access Hazards" />
        <property role="TrG5h" value="accessHazard" />
        <node concept="GmGrk" id="3yuK3TkZVor" role="GmGcz">
          <node concept="1_0LV8" id="3yuK3TkZVos" role="1_0VJ0">
            <node concept="19SGf9" id="3yuK3TkZVot" role="1_0LWR">
              <node concept="19SUe$" id="3yuK3TkZVou" role="19SJt6">
                <property role="19SUeA" value="Access to device or system without permission.&#10;Not addressed in the implementation of the system." />
              </node>
            </node>
          </node>
        </node>
        <node concept="22Mrfp" id="3yuK3TkZVov" role="22Mr8z" />
      </node>
      <node concept="3fbQ3u" id="3yuK3TkZVp4" role="3fbPAY">
        <property role="2DRQuN" value="1672949746398" />
        <property role="2DXwbs" value="rijo" />
        <property role="1ylvJX" value="Ransomeware Hazards" />
        <property role="TrG5h" value="ransomewareHazard" />
        <node concept="GmGrk" id="3yuK3TkZVp5" role="GmGcz">
          <node concept="1_0LV8" id="3yuK3TkZVp6" role="1_0VJ0">
            <node concept="19SGf9" id="3yuK3TkZVp7" role="1_0LWR">
              <node concept="19SUe$" id="3yuK3TkZVp8" role="19SJt6">
                <property role="19SUeA" value="Malware that encrypts data and demands payment.&#10;Not addressed in the implementation of the system." />
              </node>
            </node>
          </node>
        </node>
        <node concept="22Mrfp" id="3yuK3TkZVp9" role="22Mr8z" />
      </node>
      <node concept="3fbQ3u" id="3yuK3TkZVpO" role="3fbPAY">
        <property role="2DRQuN" value="1672949746398" />
        <property role="2DXwbs" value="rijo" />
        <property role="1ylvJX" value="Radio Frequency jamming Hazards" />
        <property role="TrG5h" value="radioHazard" />
        <node concept="GmGrk" id="3yuK3TkZVpP" role="GmGcz">
          <node concept="1_0LV8" id="3yuK3TkZVpQ" role="1_0VJ0">
            <node concept="19SGf9" id="3yuK3TkZVpR" role="1_0LWR">
              <node concept="19SUe$" id="3yuK3TkZVpS" role="19SJt6">
                <property role="19SUeA" value="Blocking wireless signals through frequency interference.&#10;Not addressed in the implementation of the system." />
              </node>
            </node>
          </node>
        </node>
        <node concept="22Mrfp" id="3yuK3TkZVpT" role="22Mr8z" />
      </node>
      <node concept="3fbQ3u" id="3yuK3TkZVqE" role="3fbPAY">
        <property role="2DRQuN" value="1672949746398" />
        <property role="2DXwbs" value="rijo" />
        <property role="1ylvJX" value="Botnets Hazards" />
        <property role="TrG5h" value="botnetHazard" />
        <node concept="GmGrk" id="3yuK3TkZVqF" role="GmGcz">
          <node concept="1_0LV8" id="3yuK3TkZVqG" role="1_0VJ0">
            <node concept="19SGf9" id="3yuK3TkZVqH" role="1_0LWR">
              <node concept="19SUe$" id="3yuK3TkZVqI" role="19SJt6">
                <property role="19SUeA" value="Networks of compromised devices controlled remotely.&#10;Not addressed in the implementation of the system." />
              </node>
            </node>
          </node>
        </node>
        <node concept="22Mrfp" id="3yuK3TkZVqJ" role="22Mr8z" />
      </node>
    </node>
    <node concept="3GEVxB" id="3yuK3TkZW8P" role="1BwUYK">
      <ref role="3GEb4d" node="3yuK3TkZPU$" resolve="Requirements" />
    </node>
    <node concept="3GEVxB" id="3yuK3TkZW8U" role="1BwUYK">
      <ref role="3GEb4d" node="3yuK3TkZT14" resolve="Components" />
    </node>
    <node concept="3GEVxB" id="3yuK3TkZW92" role="1BwUYK">
      <ref role="3GEb4d" node="3yuK3TkZT3h" resolve="Actors" />
    </node>
  </node>
  <node concept="3fbPIq" id="3yuK3TkZWDd">
    <property role="TrG5h" value="Parameters" />
    <ref role="G9hjw" node="3yuK3TkZPUD" resolve="DefaultDocConfig" />
    <node concept="OjmMv" id="3yuK3TkZWDe" role="tLAhV">
      <node concept="19SGf9" id="3yuK3TkZWDf" role="OjmMu">
        <node concept="19SUe$" id="3yuK3TkZWDg" role="19SJt6" />
      </node>
    </node>
    <node concept="2RsZnQ" id="3yuK3TkZWDh" role="2RsZnW" />
    <node concept="3fbQ3u" id="3yuK3TkZWDj" role="3fbPIo">
      <property role="2DRQuN" value="1673009512994" />
      <property role="2DXwbs" value="rijo" />
      <property role="1ylvJX" value="Temperature Set Point" />
      <property role="TrG5h" value="tempSetPoint" />
      <node concept="GmGrk" id="3yuK3TkZWDl" role="GmGcz">
        <node concept="1_0LV8" id="3yuK3TkZWDm" role="1_0VJ0">
          <node concept="19SGf9" id="3yuK3TkZWDn" role="1_0LWR">
            <node concept="19SUe$" id="3yuK3TkZWDo" role="19SJt6">
              <property role="19SUeA" value="Target temperature value " />
            </node>
          </node>
        </node>
      </node>
      <node concept="22Mrfp" id="3yuK3TkZWDi" role="22Mr8z" />
      <node concept="3fbQ3u" id="3yuK3TkZWDv" role="3fbPAY">
        <property role="2DRQuN" value="1673009512994" />
        <property role="2DXwbs" value="rijo" />
        <property role="1ylvJX" value="Temperature Max value" />
        <property role="TrG5h" value="tempMaxValue" />
        <node concept="GmGrk" id="3yuK3TkZWDw" role="GmGcz">
          <node concept="1_0LV8" id="3yuK3TkZWDx" role="1_0VJ0">
            <node concept="19SGf9" id="3yuK3TkZWDy" role="1_0LWR">
              <node concept="19SUe$" id="3yuK3TkZWDz" role="19SJt6">
                <property role="19SUeA" value="Maximum temperature value expected. If the value is above the sensor " />
              </node>
              <node concept="2oIDSw" id="3yuK3TkZWGs" role="19SJt6">
                <ref role="2wPqOu" node="3yuK3TkZVI0" resolve="tempSensor" />
              </node>
              <node concept="19SUe$" id="3yuK3TkZWGt" role="19SJt6">
                <property role="19SUeA" value=" has a malfunction" />
              </node>
            </node>
          </node>
        </node>
        <node concept="22Mrfp" id="3yuK3TkZWD$" role="22Mr8z" />
      </node>
      <node concept="3fbQ3u" id="3yuK3TkZWDL" role="3fbPAY">
        <property role="2DRQuN" value="1673009512994" />
        <property role="2DXwbs" value="rijo" />
        <property role="1ylvJX" value="Temperature Min value" />
        <property role="TrG5h" value="tempMinValue" />
        <node concept="GmGrk" id="3yuK3TkZWDM" role="GmGcz">
          <node concept="1_0LV8" id="3yuK3TkZWDN" role="1_0VJ0">
            <node concept="19SGf9" id="3yuK3TkZWDO" role="1_0LWR">
              <node concept="19SUe$" id="3yuK3TkZWDP" role="19SJt6">
                <property role="19SUeA" value="Minimum temperature value expected. If the value is bellow the sensor " />
              </node>
              <node concept="2oIDSw" id="3yuK3TkZWG$" role="19SJt6">
                <ref role="2wPqOu" node="3yuK3TkZVI0" resolve="tempSensor" />
              </node>
              <node concept="19SUe$" id="3yuK3TkZWG_" role="19SJt6">
                <property role="19SUeA" value=" has a malfunction" />
              </node>
            </node>
          </node>
        </node>
        <node concept="22Mrfp" id="3yuK3TkZWDQ" role="22Mr8z" />
      </node>
    </node>
    <node concept="3fbQ3u" id="3yuK3TkZWE9" role="3fbPIo">
      <property role="2DRQuN" value="1673009512994" />
      <property role="2DXwbs" value="rijo" />
      <property role="1ylvJX" value="Ambient Light Set Point" />
      <property role="TrG5h" value="amblightSetPoint" />
      <node concept="GmGrk" id="3yuK3TkZWEa" role="GmGcz">
        <node concept="1_0LV8" id="3yuK3TkZWEb" role="1_0VJ0">
          <node concept="19SGf9" id="3yuK3TkZWEc" role="1_0LWR">
            <node concept="19SUe$" id="3yuK3TkZWEd" role="19SJt6">
              <property role="19SUeA" value="Target ambient light value" />
            </node>
          </node>
        </node>
      </node>
      <node concept="22Mrfp" id="3yuK3TkZWEe" role="22Mr8z" />
      <node concept="3fbQ3u" id="3yuK3TkZWEB" role="3fbPAY">
        <property role="2DRQuN" value="1673009512994" />
        <property role="2DXwbs" value="rijo" />
        <property role="1ylvJX" value="Ambient Light Max value" />
        <property role="TrG5h" value="amblightMaxValue" />
        <node concept="GmGrk" id="3yuK3TkZWEC" role="GmGcz">
          <node concept="1_0LV8" id="3yuK3TkZWED" role="1_0VJ0">
            <node concept="19SGf9" id="3yuK3TkZWEE" role="1_0LWR">
              <node concept="19SUe$" id="3yuK3TkZWEF" role="19SJt6">
                <property role="19SUeA" value="Maximum ambient light value expected. If the value is above the sensor " />
              </node>
              <node concept="2oIDSw" id="3yuK3TkZWGI" role="19SJt6">
                <ref role="2wPqOu" node="3yuK3TkZVLg" resolve="amblightSensor" />
              </node>
              <node concept="19SUe$" id="3yuK3TkZWGJ" role="19SJt6">
                <property role="19SUeA" value=" has a malfunction" />
              </node>
            </node>
          </node>
        </node>
        <node concept="22Mrfp" id="3yuK3TkZWEG" role="22Mr8z" />
      </node>
      <node concept="3fbQ3u" id="3yuK3TkZWEH" role="3fbPAY">
        <property role="2DRQuN" value="1673009512994" />
        <property role="2DXwbs" value="rijo" />
        <property role="1ylvJX" value="Ambient Light Min value" />
        <property role="TrG5h" value="amblightMinValue" />
        <node concept="GmGrk" id="3yuK3TkZWEI" role="GmGcz">
          <node concept="1_0LV8" id="3yuK3TkZWEJ" role="1_0VJ0">
            <node concept="19SGf9" id="3yuK3TkZWEK" role="1_0LWR">
              <node concept="19SUe$" id="3yuK3TkZWEL" role="19SJt6">
                <property role="19SUeA" value="Minimum ambient light value expected. If the value is bellow the sensor " />
              </node>
              <node concept="2oIDSw" id="3yuK3TkZWGP" role="19SJt6">
                <ref role="2wPqOu" node="3yuK3TkZVLg" resolve="amblightSensor" />
              </node>
              <node concept="19SUe$" id="3yuK3TkZWGQ" role="19SJt6">
                <property role="19SUeA" value=" has a malfunction" />
              </node>
            </node>
          </node>
        </node>
        <node concept="22Mrfp" id="3yuK3TkZWEM" role="22Mr8z" />
      </node>
    </node>
    <node concept="3fbQ3u" id="3yuK3TkZWKu" role="3fbPIo">
      <property role="2DRQuN" value="1673009512994" />
      <property role="2DXwbs" value="rijo" />
      <property role="1ylvJX" value="Actuator Timeout value" />
      <property role="TrG5h" value="actTimeoutValue" />
      <node concept="GmGrk" id="3yuK3TkZWKv" role="GmGcz">
        <node concept="1_0LV8" id="3yuK3TkZWKw" role="1_0VJ0">
          <node concept="19SGf9" id="3yuK3TkZWKx" role="1_0LWR">
            <node concept="19SUe$" id="3yuK3TkZWKy" role="19SJt6">
              <property role="19SUeA" value="Expected elapsed time for an actuator to reach a certain value. If exceeded the actuator has a malfunction" />
            </node>
          </node>
        </node>
      </node>
      <node concept="22Mrfp" id="3yuK3TkZWK_" role="22Mr8z" />
    </node>
    <node concept="3GEVxB" id="3yuK3TkZWGx" role="1BwUYK">
      <ref role="3GEb4d" node="3yuK3TkZT14" resolve="Components" />
    </node>
  </node>
</model>

