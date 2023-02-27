<?xml version="1.0" encoding="UTF-8"?>
<model ref="r:61a85324-7a99-493d-bcec-e00c7505daea(moore_stateMachine.generator.templates@generator)">
  <persistence version="9" />
  <languages>
    <use id="37c2cb43-4835-4f1d-b147-4442de330b2c" name="moore_stateMachine" version="0" />
    <devkit ref="a2eb3a43-fcc2-4200-80dc-c60110c4862d(jetbrains.mps.devkit.templates)" />
  </languages>
  <imports>
    <import index="llzd" ref="r:3ea8c113-72f6-4a38-a9ee-f97352d0bed1(moore_stateMachine.structure)" />
    <import index="guwi" ref="6354ebe7-c22a-4a0f-ac54-50b52ab9b065/java:java.io(JDK/)" />
    <import index="wyt6" ref="6354ebe7-c22a-4a0f-ac54-50b52ab9b065/java:java.lang(JDK/)" implicit="true" />
    <import index="l32" ref="r:32bb98c5-10b8-4800-84fc-5c15541c8b6e(sm1.generator.templates@generator)" implicit="true" />
  </imports>
  <registry>
    <language id="f3061a53-9226-4cc5-a443-f952ceaf5816" name="jetbrains.mps.baseLanguage">
      <concept id="1202948039474" name="jetbrains.mps.baseLanguage.structure.InstanceMethodCallOperation" flags="nn" index="liA8E" />
      <concept id="1465982738277781862" name="jetbrains.mps.baseLanguage.structure.PlaceholderMember" flags="nn" index="2tJIrI" />
      <concept id="1197027756228" name="jetbrains.mps.baseLanguage.structure.DotExpression" flags="nn" index="2OqwBi">
        <child id="1197027771414" name="operand" index="2Oq$k0" />
        <child id="1197027833540" name="operation" index="2OqNvi" />
      </concept>
      <concept id="1145552977093" name="jetbrains.mps.baseLanguage.structure.GenericNewExpression" flags="nn" index="2ShNRf">
        <child id="1145553007750" name="creator" index="2ShVmc" />
      </concept>
      <concept id="1070475926800" name="jetbrains.mps.baseLanguage.structure.StringLiteral" flags="nn" index="Xl_RD">
        <property id="1070475926801" name="value" index="Xl_RC" />
      </concept>
      <concept id="1081236700938" name="jetbrains.mps.baseLanguage.structure.StaticMethodDeclaration" flags="ig" index="2YIFZL" />
      <concept id="1070533707846" name="jetbrains.mps.baseLanguage.structure.StaticFieldReference" flags="nn" index="10M0yZ">
        <reference id="1144433057691" name="classifier" index="1PxDUh" />
      </concept>
      <concept id="1070534760951" name="jetbrains.mps.baseLanguage.structure.ArrayType" flags="in" index="10Q1$e">
        <child id="1070534760952" name="componentType" index="10Q1$1" />
      </concept>
      <concept id="1068390468198" name="jetbrains.mps.baseLanguage.structure.ClassConcept" flags="ig" index="312cEu" />
      <concept id="1068431474542" name="jetbrains.mps.baseLanguage.structure.VariableDeclaration" flags="ng" index="33uBYm">
        <child id="1068431790190" name="initializer" index="33vP2m" />
      </concept>
      <concept id="1068498886296" name="jetbrains.mps.baseLanguage.structure.VariableReference" flags="nn" index="37vLTw">
        <reference id="1068581517664" name="variableDeclaration" index="3cqZAo" />
      </concept>
      <concept id="1068498886292" name="jetbrains.mps.baseLanguage.structure.ParameterDeclaration" flags="ir" index="37vLTG" />
      <concept id="4972933694980447171" name="jetbrains.mps.baseLanguage.structure.BaseVariableDeclaration" flags="ng" index="19Szcq">
        <child id="5680397130376446158" name="type" index="1tU5fm" />
      </concept>
      <concept id="1068580123132" name="jetbrains.mps.baseLanguage.structure.BaseMethodDeclaration" flags="ng" index="3clF44">
        <child id="1068580123133" name="returnType" index="3clF45" />
        <child id="1068580123134" name="parameter" index="3clF46" />
        <child id="1068580123135" name="body" index="3clF47" />
      </concept>
      <concept id="1068580123155" name="jetbrains.mps.baseLanguage.structure.ExpressionStatement" flags="nn" index="3clFbF">
        <child id="1068580123156" name="expression" index="3clFbG" />
      </concept>
      <concept id="1068580123157" name="jetbrains.mps.baseLanguage.structure.Statement" flags="nn" index="3clFbH" />
      <concept id="1068580123136" name="jetbrains.mps.baseLanguage.structure.StatementList" flags="sn" stub="5293379017992965193" index="3clFbS">
        <child id="1068581517665" name="statement" index="3cqZAp" />
      </concept>
      <concept id="1068580320020" name="jetbrains.mps.baseLanguage.structure.IntegerConstant" flags="nn" index="3cmrfG">
        <property id="1068580320021" name="value" index="3cmrfH" />
      </concept>
      <concept id="1068581242864" name="jetbrains.mps.baseLanguage.structure.LocalVariableDeclarationStatement" flags="nn" index="3cpWs8">
        <child id="1068581242865" name="localVariableDeclaration" index="3cpWs9" />
      </concept>
      <concept id="1068581242863" name="jetbrains.mps.baseLanguage.structure.LocalVariableDeclaration" flags="nr" index="3cpWsn" />
      <concept id="1068581517677" name="jetbrains.mps.baseLanguage.structure.VoidType" flags="in" index="3cqZAl" />
      <concept id="1204053956946" name="jetbrains.mps.baseLanguage.structure.IMethodCall" flags="ng" index="1ndlxa">
        <reference id="1068499141037" name="baseMethodDeclaration" index="37wK5l" />
        <child id="1068499141038" name="actualArgument" index="37wK5m" />
      </concept>
      <concept id="1212685548494" name="jetbrains.mps.baseLanguage.structure.ClassCreator" flags="nn" index="1pGfFk" />
      <concept id="1107461130800" name="jetbrains.mps.baseLanguage.structure.Classifier" flags="ng" index="3pOWGL">
        <child id="5375687026011219971" name="member" index="jymVt" unordered="true" />
      </concept>
      <concept id="1107535904670" name="jetbrains.mps.baseLanguage.structure.ClassifierType" flags="in" index="3uibUv">
        <reference id="1107535924139" name="classifier" index="3uigEE" />
      </concept>
      <concept id="1178549954367" name="jetbrains.mps.baseLanguage.structure.IVisible" flags="ng" index="1B3ioH">
        <child id="1178549979242" name="visibility" index="1B3o_S" />
      </concept>
      <concept id="1146644602865" name="jetbrains.mps.baseLanguage.structure.PublicVisibility" flags="nn" index="3Tm1VV" />
    </language>
    <language id="b401a680-8325-4110-8fd3-84331ff25bef" name="jetbrains.mps.lang.generator">
      <concept id="1095416546421" name="jetbrains.mps.lang.generator.structure.MappingConfiguration" flags="ig" index="bUwia">
        <child id="1167514678247" name="rootMappingRule" index="3lj3bC" />
      </concept>
      <concept id="1168619357332" name="jetbrains.mps.lang.generator.structure.RootTemplateAnnotation" flags="lg" index="n94m4">
        <reference id="1168619429071" name="applicableConcept" index="n9lRv" />
      </concept>
      <concept id="1167169308231" name="jetbrains.mps.lang.generator.structure.BaseMappingRule" flags="ng" index="30H$t8">
        <reference id="1167169349424" name="applicableConcept" index="30HIoZ" />
      </concept>
      <concept id="1167514355419" name="jetbrains.mps.lang.generator.structure.Root_MappingRule" flags="lg" index="3lhOvk">
        <reference id="1167514355421" name="template" index="3lhOvi" />
      </concept>
    </language>
    <language id="ceab5195-25ea-4f22-9b92-103b95ca8c0c" name="jetbrains.mps.lang.core">
      <concept id="1133920641626" name="jetbrains.mps.lang.core.structure.BaseConcept" flags="ng" index="2VYdi">
        <child id="5169995583184591170" name="smodelAttribute" index="lGtFl" />
      </concept>
      <concept id="1169194658468" name="jetbrains.mps.lang.core.structure.INamedConcept" flags="ng" index="TrEIO">
        <property id="1169194664001" name="name" index="TrG5h" />
      </concept>
    </language>
  </registry>
  <node concept="bUwia" id="2nvBbcl1AFb">
    <property role="TrG5h" value="main" />
    <node concept="3lhOvk" id="6fowutXAFLf" role="3lj3bC">
      <ref role="30HIoZ" to="llzd:2nvBbcl1AFg" resolve="StateMachine" />
      <ref role="3lhOvi" node="2nvBbcl1AFb" resolve="main" />
    </node>
    <node concept="3lhOvk" id="6fowutXAVZs" role="3lj3bC">
      <ref role="30HIoZ" to="llzd:2nvBbcl1AFg" resolve="StateMachine" />
      <ref role="3lhOvi" node="6fowutXAWfE" resolve="$AStateMachine" />
    </node>
    <node concept="3lhOvk" id="6fowutXAW7o" role="3lj3bC">
      <ref role="30HIoZ" to="llzd:2nvBbcl1AFg" resolve="StateMachine" />
    </node>
  </node>
  <node concept="312cEu" id="6fowutXBpG4">
    <property role="TrG5h" value="Main" />
    <node concept="2YIFZL" id="6zTXQ1YJe3b" role="jymVt">
      <property role="TrG5h" value="main" />
      <node concept="3clFbS" id="6zTXQ1YJe3d" role="3clF47">
        <node concept="3clFbF" id="6zTXQ1YJe3e" role="3cqZAp">
          <node concept="2OqwBi" id="6zTXQ1YJe3f" role="3clFbG">
            <node concept="10M0yZ" id="6zTXQ1YJe3g" role="2Oq$k0">
              <ref role="3cqZAo" to="wyt6:~System.out" resolve="out" />
              <ref role="1PxDUh" to="wyt6:~System" resolve="System" />
            </node>
            <node concept="liA8E" id="6zTXQ1YJe3h" role="2OqNvi">
              <ref role="37wK5l" to="guwi:~PrintStream.println(java.lang.String)" resolve="println" />
              <node concept="Xl_RD" id="6zTXQ1YJe3i" role="37wK5m">
                <property role="Xl_RC" value="Executing the State Machine" />
              </node>
            </node>
          </node>
        </node>
        <node concept="3cpWs8" id="2CUMcacg4kv" role="3cqZAp">
          <node concept="3cpWsn" id="2CUMcacg4kw" role="3cpWs9">
            <property role="TrG5h" value="stateMachine" />
            <node concept="3uibUv" id="2CUMcacg4kx" role="1tU5fm">
              <ref role="3uigEE" to="l32:6uB2takTx1K" resolve="AStateMachine" />
            </node>
            <node concept="2ShNRf" id="2CUMcacg4o0" role="33vP2m">
              <node concept="1pGfFk" id="2CUMcacg5yi" role="2ShVmc">
                <ref role="37wK5l" to="l32:6uB2takTStt" resolve="AStateMachine" />
              </node>
            </node>
          </node>
        </node>
        <node concept="3clFbF" id="2CUMcacg5Gp" role="3cqZAp">
          <node concept="2OqwBi" id="2CUMcacg5Nn" role="3clFbG">
            <node concept="37vLTw" id="2CUMcacg5Gn" role="2Oq$k0">
              <ref role="3cqZAo" node="2CUMcacg4kw" resolve="sm" />
            </node>
            <node concept="liA8E" id="2CUMcacg5Vd" role="2OqNvi">
              <ref role="37wK5l" to="l32:6uB2takTMGF" resolve="displayState" />
            </node>
          </node>
        </node>
        <node concept="3clFbF" id="2CUMcacg5Zo" role="3cqZAp">
          <node concept="2OqwBi" id="2CUMcacg60v" role="3clFbG">
            <node concept="37vLTw" id="2CUMcacg5Zm" role="2Oq$k0">
              <ref role="3cqZAo" node="2CUMcacg4kw" resolve="sm" />
            </node>
            <node concept="liA8E" id="2CUMcacg63K" role="2OqNvi">
              <ref role="37wK5l" to="l32:780SfjpvTKa" resolve="onEvent" />
              <node concept="3cmrfG" id="2CUMcacg6jq" role="37wK5m">
                <property role="3cmrfH" value="0" />
              </node>
            </node>
          </node>
        </node>
        <node concept="3clFbF" id="2CUMcacg6p5" role="3cqZAp">
          <node concept="2OqwBi" id="2CUMcacg6wJ" role="3clFbG">
            <node concept="37vLTw" id="2CUMcacg6p3" role="2Oq$k0">
              <ref role="3cqZAo" node="2CUMcacg4kw" resolve="sm" />
            </node>
            <node concept="liA8E" id="2CUMcacg6BO" role="2OqNvi">
              <ref role="37wK5l" to="l32:6uB2takTMGF" resolve="displayState" />
            </node>
          </node>
        </node>
        <node concept="3clFbF" id="P9RR6vl9I5" role="3cqZAp">
          <node concept="2OqwBi" id="P9RR6vl9I6" role="3clFbG">
            <node concept="37vLTw" id="P9RR6vl9I7" role="2Oq$k0">
              <ref role="3cqZAo" node="2CUMcacg4kw" resolve="sm" />
            </node>
            <node concept="liA8E" id="P9RR6vl9I8" role="2OqNvi">
              <ref role="37wK5l" to="l32:780SfjpvTKa" resolve="onEvent" />
              <node concept="3cmrfG" id="P9RR6vl9O1" role="37wK5m">
                <property role="3cmrfH" value="1" />
              </node>
            </node>
          </node>
        </node>
        <node concept="3clFbF" id="P9RR6vl9Ia" role="3cqZAp">
          <node concept="2OqwBi" id="P9RR6vl9Ib" role="3clFbG">
            <node concept="37vLTw" id="P9RR6vl9Ic" role="2Oq$k0">
              <ref role="3cqZAo" node="2CUMcacg4kw" resolve="sm" />
            </node>
            <node concept="liA8E" id="P9RR6vl9Id" role="2OqNvi">
              <ref role="37wK5l" to="l32:6uB2takTMGF" resolve="displayState" />
            </node>
          </node>
        </node>
        <node concept="3clFbH" id="P9RR6vl9sp" role="3cqZAp" />
      </node>
      <node concept="3cqZAl" id="6zTXQ1YJe3k" role="3clF45" />
      <node concept="3Tm1VV" id="6zTXQ1YJe3j" role="1B3o_S" />
      <node concept="37vLTG" id="6zTXQ1YJe8a" role="3clF46">
        <property role="TrG5h" value="args" />
        <node concept="10Q1$e" id="6zTXQ1YJedD" role="1tU5fm">
          <node concept="3uibUv" id="6zTXQ1YJe89" role="10Q1$1">
            <ref role="3uigEE" to="wyt6:~String" resolve="String" />
          </node>
        </node>
      </node>
    </node>
    <node concept="2tJIrI" id="6fowutXBqCK" role="jymVt" />
    <node concept="3Tm1VV" id="6fowutXBpG5" role="1B3o_S" />
    <node concept="n94m4" id="6fowutXBpG6" role="lGtFl">
      <ref role="n9lRv" to="llzd:2nvBbcl1AFg" resolve="StateMachine" />
    </node>
  </node>
  <node concept="312cEu" id="6fowutXBuGG">
    <property role="TrG5h" value="$" />
    <node concept="2tJIrI" id="6fowutXBxlJ" role="jymVt" />
    <node concept="3Tm1VV" id="6fowutXBuGH" role="1B3o_S" />
    <node concept="n94m4" id="6fowutXBuGI" role="lGtFl">
      <ref role="n9lRv" to="llzd:2nvBbcl1AFg" resolve="StateMachine" />
    </node>
  </node>
</model>

